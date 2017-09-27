//
//  CalculatorBrain.swift
//  Calculator
//
//  Created by Anton on 06.06.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import Foundation

struct CalculatorBrain {
    // API
    mutating func setOperand(_ value:Double) {
        internalProgram.append(OpStack.operand(value))
    }
    mutating func setOperand(variable named: String) {
        internalProgram.append(OpStack.variable(named))
    }
    
    mutating func performOperationInBrain(_ mathematicalSymbol:String) {
        internalProgram.append(OpStack.operation(mathematicalSymbol))
    }
    
    mutating func clear() {
        internalProgram.removeAll()
    }
    
    @available(iOS, deprecated, message: "No longer needed")
    var description: String {
        return evaluate().description
    }
    
    @available(iOS, deprecated, message: "No longer needed")
    var resultIsPending:Bool {
        return evaluate().isPending
    }
    
    @available(iOS, deprecated, message: "No longer needed")
    var result:Double {
        return evaluate().result ?? 0
    }
    
    mutating func undo() {
        if !internalProgram.isEmpty {
            internalProgram = Array(internalProgram.dropLast())
        }
    }
    
    //end of API
    
    struct BinaryOperationContainer {
        var symbol:String
        var function: (Double,Double)->Double
        var firstOperand:Double
        func performBinaryOperation (with secondOperand:Double)->Double {
            return function(firstOperand, secondOperand)
        }
    }
    enum operations {
        case nullaryOperation(()->Double)
        case constant(Double)
        case unaryOperation((Double)->Double)
        case binaryOperation((Double,Double)->Double)
        case equal
    }
    
    private var operation:Dictionary = [
        "=":operations.equal,
        "+":operations.binaryOperation({$0 + $1}),
        "×":operations.binaryOperation({$0 * $1}),
        "-":operations.binaryOperation({$0 - $1}),
        "÷":operations.binaryOperation({$0 / $1}),
        "π":operations.constant(Double.pi),
        "√":operations.unaryOperation(sqrt),
        "±":operations.unaryOperation({-$0}),
        "sin":operations.unaryOperation({sin($0)}),
        "cos":operations.unaryOperation({cos($0)}),
        "tan":operations.unaryOperation({tan($0)}),
        "sin⁻¹":operations.unaryOperation({asin($0)}),
        "cos⁻¹":operations.unaryOperation({acos($0)}),
        "tan⁻¹":operations.unaryOperation({atan($0)}),
        "e":operations.constant(M_E),
        "ln":operations.unaryOperation({log10($0)}),
        "x²":operations.unaryOperation({$0 * $0}),
        "x⁻¹":operations.unaryOperation({1 / $0}),
        "xʸ":operations.binaryOperation({pow($0, $1)}),
        "Ran":operations.nullaryOperation(random)
    ]
    
    //general function of evaluating
    internal func evaluate(using variables: Dictionary<String,Double>? = nil)
        -> (result: Double?, isPending: Bool, description: String) {
            
            //supporting nested func and variables
            var binaryOperationValue:BinaryOperationContainer?
            var operand:Double?
            var historyOfOperations:OperationsHistory = OperationsHistory()
            
            
            func performBinaryOperation() {
                if (binaryOperationValue != nil) {
                    operand = binaryOperationValue!.performBinaryOperation(with: operand ?? 0)
                    binaryOperationValue = nil
                }
            }
            func performOperation(_ mathematicalSymbol:String) {
                if let curOperation = operation[mathematicalSymbol] {
                    historyOfOperations.addOperation(mathematicalSymbol,operand ?? 0)
                    switch curOperation {
                    case .nullaryOperation(let function):
                        operand = function()
                        
                    case .unaryOperation(let function):
                        operand = function(operand ?? 0)
                        
                    case .constant(let value) :
                        operand = value
                        
                    case .binaryOperation(let function):
                        performBinaryOperation()
                        binaryOperationValue = BinaryOperationContainer(symbol: mathematicalSymbol, function: function, firstOperand: operand ?? 0)
                        
                    case .equal:
                        performBinaryOperation()
                    }
                }
                
                historyOfOperations.setOperandAfterPerformnig(operand ?? 0)
            }
            //end of supporting func qnd variables
            
            for item in internalProgram {
                switch item {
                case .operand(let curOperand):
                    operand = curOperand
                    
                case .operation(let operation):
                    //perform internal operation
                    performOperation(operation)
                    
                case .variable(let variable):
                    //perform variable with supplied Dictionary
                    if let curVar = variables?[variable] {
                        operand = curVar
                    } else {
                        operand = 0
                    }
                    historyOfOperations.addOperation(variable, operand ?? 0, withVariable: true)
                    break;
                }
            }
            return (operand, binaryOperationValue != nil, historyOfOperations.getStringHistory())
            
            
            
    }
    //end of general function of evaluating
    
    
    
    
    
    struct OperationsHistory{
        private var resultArray = [String]()
        private var temporaryArrayBeforeEqualSign = [String]()
        private var needToSkip = false
        private var lastItemIsMathSign = true
        private var lastOperandAfterPerforming :Double  = 0
        private var thereIsVariable = false
        
        mutating func addOperation(_ mathematicalSymbol:String,_ operand: Double, withVariable inMemory:Bool = false) {
            if inMemory {
                thereIsVariable = true
                temporaryArrayBeforeEqualSign.append(mathematicalSymbol)
                needToSkip = true
                return
            }
            switch mathematicalSymbol {
            case "=":
                addOperand(operand)
                moveTemporaryArrayToResultAsString()
                temporaryArrayBeforeEqualSign.removeAll()
                needToSkip = true
            case "√",
                 "sin",
                 "cos",
                 "tan",
                 "sin⁻¹",
                 "cos⁻¹",
                 "tan⁻¹",
                 "ln":
                addOperand(operand)
                putSignInAppropriatePosition(mathematicalSymbol)
                needToSkip = true
                break
            case "π","e":
                temporaryArrayBeforeEqualSign.append(mathematicalSymbol)
                needToSkip = true
                break
            case "⌫":
                deleteLastItem()
            default:
                addOperand(operand)
                temporaryArrayBeforeEqualSign.append(mathematicalSymbol)
                lastItemIsMathSign = true
                break
            }
        }
        
        mutating private func deleteLastItem() {
            if !temporaryArrayBeforeEqualSign.isEmpty {
                temporaryArrayBeforeEqualSign.remove(at: temporaryArrayBeforeEqualSign.count - 1)
                temporaryArrayBeforeEqualSign.remove(at: temporaryArrayBeforeEqualSign.count - 1)
                
            }
        }
        
        mutating func setOperandAfterPerformnig(_ operand: Double) {
            lastOperandAfterPerforming = operand
        }
        
        
        mutating private func addOperand(_ operand:Double ) {
            if !lastItemIsMathSign && lastOperandAfterPerforming != operand && !thereIsVariable {
                clearHistory()
                needToSkip = false
            }
            if needToSkip {
                needToSkip = false
            } else {
                temporaryArrayBeforeEqualSign.append(String(operand))
                lastItemIsMathSign = false
                //lastOperand = operand
            }
        }
        
        
        mutating func clearHistory() {
            temporaryArrayBeforeEqualSign.removeAll()
            resultArray.removeAll()
        }
        
        mutating private func putSignInAppropriatePosition(_ mathematicalSymbol: String) {
            if temporaryArrayBeforeEqualSign.isEmpty {
                if !resultArray.isEmpty {
                    //we need put sqrt in resultArray
                    let curLastIndex = resultArray.count - 1
                    var lastValue = resultArray[curLastIndex]
                    lastValue = "\(mathematicalSymbol)(" + lastValue + ")"
                    resultArray[curLastIndex] = lastValue
                }
                
            } else {
                let curLastIndex = temporaryArrayBeforeEqualSign.count - 1
                let sign = temporaryArrayBeforeEqualSign[curLastIndex]
                temporaryArrayBeforeEqualSign[curLastIndex] = "\(mathematicalSymbol)"
                temporaryArrayBeforeEqualSign.append("(")
                temporaryArrayBeforeEqualSign.append(sign)
                temporaryArrayBeforeEqualSign.append(")")
                
            }
            lastItemIsMathSign = false
        }
        
        mutating private func moveTemporaryArrayToResultAsString() {
            var res = ""
            if !temporaryArrayBeforeEqualSign.isEmpty {
                for item in temporaryArrayBeforeEqualSign {
                    res += item
                }
            }
            resultArray.append(res)
        }
        
        func getStringHistory() -> String {
            var res = ""
            if !resultArray.isEmpty {
                for item in resultArray {
                    res += item
                }
            }
            if !temporaryArrayBeforeEqualSign.isEmpty {
                for item in temporaryArrayBeforeEqualSign {
                    res += item
                }
            }
            return res
        }
    }
    
}
//supporting
enum OpStack {
    case operand(Double)
    case operation(String)
    case variable(String)
}

private var internalProgram = [OpStack]()
// end of supporting

private func random()->Double {
    return Double(arc4random())/Double(UInt32.max)
}
