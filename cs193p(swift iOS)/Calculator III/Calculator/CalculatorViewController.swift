//
//  ViewController.swift
//  Calculator
//
//  Created by Anton on 31.05.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit


class CalculatorViewController: UIViewController, UISplitViewControllerDelegate {
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.isNavigationBarHidden = true
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        self.navigationController?.isNavigationBarHidden = false
    }
    
    func splitViewController(_ splitViewController: UISplitViewController, collapseSecondary secondaryViewController: UIViewController, onto primaryViewController: UIViewController) -> Bool {
        //if primaryViewController. == self {
          return true
        //}
    }
    
    override func awakeFromNib() {
        super.awakeFromNib()
        self.splitViewController?.delegate = self
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        //let seg = segue.identifier
        var receiver = segue.destination
        if let navigationVC = segue.destination as? UINavigationController {
            receiver = navigationVC.visibleViewController ?? receiver
        }
        
        if var destination = receiver as? GraphViewController {
            //receiver.Label?.text = "Was set"
            //receiver.textLabel = "was set"
            destination.yForx = { [weak weakSelf = self] x in weakSelf?.arrayOfVariables?["M"] = x
                return  weakSelf?.brain.evaluate(using: weakSelf?.arrayOfVariables).result 
            }
            destination.navigationItem.title = "y = " + brain.evaluate(using: arrayOfVariables).description
        }
    }
    
    
    override func shouldPerformSegue(withIdentifier identifier: String, sender: Any?) -> Bool {
        if identifier == "showGraphSegue" {
            let result = brain.evaluate()
            return !result.isPending
        }
        return false
    }
    
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

