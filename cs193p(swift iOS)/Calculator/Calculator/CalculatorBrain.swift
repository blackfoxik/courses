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
        var tmpDescription:String
        var descriptionFunction: (String, String) -> String
        func performBinaryStringOperation(with secondStringOperand: String) -> String {
            return descriptionFunction(tmpDescription, secondStringOperand)
        }
    }
    enum operations {
        case nullaryOperation(()->Double, String)
        case constant(Double, String)
        case unaryOperation((Double)->Double, (String)->String)
        case binaryOperation((Double,Double)->Double, (String, String)->String)
        case equal
    }
    
    private var operation:Dictionary = [
        "=":operations.equal,
        "+":operations.binaryOperation({$0 + $1}, {"\($0) + \($1)"}),
        "×":operations.binaryOperation({$0 * $1}, {"\($0) × \($1)"}),
        "-":operations.binaryOperation({$0 - $1}, {"\($0) - \($1)"}),
        "÷":operations.binaryOperation({$0 / $1}, {"\($0) ÷ \($1)"}),
        "π":operations.constant(Double.pi, "π"),
        "√":operations.unaryOperation(sqrt, {"√(\($0))"}),
        "±":operations.unaryOperation({-$0}, {"±(\($0))"}),
        "sin":operations.unaryOperation({sin($0)}, {"sin(\($0))"}),
        "cos":operations.unaryOperation({cos($0)}, {"cos(\($0))"}),
        "tan":operations.unaryOperation({tan($0)}, {"tan(\($0))"}),
        "sin⁻¹":operations.unaryOperation({asin($0)}, {"sin⁻¹(\($0))"}),
        "cos⁻¹":operations.unaryOperation({acos($0)}, {"cos⁻¹(\($0))"}),
        "tan⁻¹":operations.unaryOperation({atan($0)}, {"tan⁻¹(\($0))"}),
        "e":operations.constant(M_E, "e"),
        "ln":operations.unaryOperation({log10($0)}, {"ln(\($0))"}),
        "x²":operations.unaryOperation({$0 * $0}, {"(\($0)²)"}),
        "x⁻¹":operations.unaryOperation({1 / $0}, {"(\($0))⁻¹"}),
        "xʸ":operations.binaryOperation({pow($0, $1)}, {"\($0) ^ \($1)"}),
        "Ran":operations.nullaryOperation(random, "ran")
    ]
    
    //general function of evaluating
    internal func evaluate(using variables: Dictionary<String,Double>? = nil)
        -> (result: Double?, isPending: Bool, description: String) {
            
            //supporting nested func and variables
            var binaryOperationValue: BinaryOperationContainer?
            var operand: Double?
            var stringOperand: String = ""
            
            var description: String {
                get {
                    if binaryOperationValue == nil {
                        return stringOperand
                    } else {
                        return binaryOperationValue?.descriptionFunction(String(binaryOperationValue?.firstOperand ?? 0), stringOperand) ?? ""
                    }
                }
            }
            
            func performBinaryOperation() {
                if (binaryOperationValue != nil) {
                    operand = binaryOperationValue!.performBinaryOperation(with: operand ?? 0)
                    stringOperand = binaryOperationValue!.performBinaryStringOperation(with: stringOperand)
                    binaryOperationValue = nil
                }
            }
     
            
            func performOperation(_ mathematicalSymbol:String) {
                if let curOperation = operation[mathematicalSymbol] {
                    switch curOperation {
                    case .nullaryOperation(let function, let descriptionFunction):
                        operand = function()
                        stringOperand = descriptionFunction
                    case .unaryOperation(let function, let strFunction):
                        operand = function(operand ?? 0)
                        stringOperand = strFunction(stringOperand)
                    case .constant(let value, let strConstant):
                        operand = value
                        stringOperand = strConstant
                        
                    case .binaryOperation(let function, let descriptionFunction):
                        performBinaryOperation()
                        binaryOperationValue = BinaryOperationContainer(symbol: mathematicalSymbol, function: function, firstOperand: operand ?? 0, tmpDescription: stringOperand, descriptionFunction: descriptionFunction)
                        operand = 0
                        stringOperand = ""
                    case .equal:
                        performBinaryOperation()
                    }
                }
                
            }
            //end of supporting func qnd variables
            
            for item in internalProgram {
                switch item {
                case .operand(let curOperand):
                    operand = curOperand
                    stringOperand = formatter.string(from: NSNumber(value: curOperand)) ?? ""
                    
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
                    stringOperand = variable
                    break;
                }
            }
        
            return (operand, binaryOperationValue != nil, description)
            
            
            
    }
    //end of general function of evaluating
    
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

let formatter:NumberFormatter = {
    let formatter = NumberFormatter()
    formatter.numberStyle = .decimal
    formatter.maximumFractionDigits = 6
    formatter.notANumberSymbol = "Error"
    formatter.groupingSeparator = " "
    formatter.locale = Locale.current
    return formatter
    
} ()
