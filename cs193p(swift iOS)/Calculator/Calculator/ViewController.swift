//
//  ViewController.swift
//  Calculator
//
//  Created by Anton on 31.05.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit


class ViewController: UIViewController {
    
    @IBOutlet weak var memoryDisplay: UILabel!
    @IBOutlet weak var display: UILabel!
    
    var userIsInTheMiddleOfTyping = false
    var arrayOfVariables:[String: Double]?
    var brain:CalculatorBrain = CalculatorBrain()
    @IBOutlet weak var displaySequence: UILabel!
    
    @IBAction func evaluate(_ sender: UIButton) {
        displayValue = brain.evaluate(using: arrayOfVariables).result ?? 0
    }
    var displayValue: Double {
        get {
            return Double(display.text!)!
        }
        set {
            display.text = formatter.string(from:NSNumber(value: newValue)) ?? ""
        }
    }
   
    @IBAction func touchDigit(_ sender: UIButton) {
        
        let digit = sender.currentTitle!
        
        if (display.text?.contains("."))! && digit == "." {
            return
        }
        
        if userIsInTheMiddleOfTyping {
            let textCurrentlyInDisplay = display.text!
            display.text = textCurrentlyInDisplay + digit
        } else {
            display.text = digit
            userIsInTheMiddleOfTyping = true
        }
    }
    
    @IBAction func performOperation(_ sender: UIButton) {
        if userIsInTheMiddleOfTyping {
            brain.setOperand(displayValue)
            userIsInTheMiddleOfTyping = false
        }
        
        if let mathematicalSymbol = sender.currentTitle {
            brain.performOperationInBrain(mathematicalSymbol)
        }
        displayValue = brain.evaluate(using: arrayOfVariables).result ?? 0
        showHistory()
    }
    
    @IBAction func setM(_ sender: UIButton) {
        if (arrayOfVariables?["M"] != nil) {
            arrayOfVariables?["M"] = displayValue
        } else {
            arrayOfVariables = ["M":displayValue]
        }
        memoryDisplay?.text = "M = \(display?.text ?? " ")"
        displayValue = brain.evaluate(using: arrayOfVariables).result ?? 0
        userIsInTheMiddleOfTyping = false
    }
    
    @IBAction func getM(_ sender: UIButton) {
        brain.setOperand(variable: "M")
        displayValue = brain.evaluate(using: arrayOfVariables).result ?? 0
    }

    @IBAction func undo(_ sender: Any) {
        if display?.text?.characters.count == 1 {
            displayValue = 0
            return
        }
        if  userIsInTheMiddleOfTyping {
            var displayString = display?.text
            let indexBeforeEnd = displayString?.index(before: (displayString?.endIndex)!)
            displayString?.remove(at: indexBeforeEnd!)
            display?.text = displayString
        } else {
            brain.undo()
            displayValue = brain.evaluate(using: arrayOfVariables).result ?? 0
        }
    }
    @IBAction func clear(_ sender: UIButton) {
        brain.clear()
        displayValue = 0
        userIsInTheMiddleOfTyping = false
        arrayOfVariables = nil
        memoryDisplay?.text = " "
        showHistory()
    }
    private func showHistory() {
        //if brain.resultIsPending {
        if brain.evaluate(using: arrayOfVariables).isPending {
            displaySequence.text = brain.evaluate(using: arrayOfVariables).description + "..."
        } else {
            if brain.evaluate(using: arrayOfVariables).result != nil {
                displaySequence.text = brain.evaluate(using: arrayOfVariables).description + "="
            }
            else {
                displaySequence.text = " "
            }
        }
    }
}

