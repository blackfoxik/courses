//
//  EmotionsViewController.swift
//  FaceIt
//
//  Created by Anton on 23.06.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit

class EmotionsViewController: UIViewController {

    
    // MARK: - Navigation

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
       var destinationViewController = segue.destination
        if let navigationController = destinationViewController as? UINavigationController {
            destinationViewController = navigationController.visibleViewController ?? destinationViewController
        }
        if let faceViewController = destinationViewController as? FaceViewController {
            if let idetnifier = segue.identifier {
                if let expression = emotionalFaces[idetnifier] {
                    faceViewController.expression = expression
                    faceViewController.navigationItem.title = (sender as? UIButton)?.currentTitle
                }
            }
        }
    }
 
    private let emotionalFaces: Dictionary<String, FacialExpression> = [
        "sad" : FacialExpression(eyes: .closed, mouth: .frown),
        "happy" : FacialExpression(eyes: .open, mouth: .smile),
        "worried" : FacialExpression(eyes: .open, mouth: .smirk)
    ]
}
