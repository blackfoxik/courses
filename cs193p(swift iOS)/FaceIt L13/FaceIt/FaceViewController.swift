//
//  ViewController.swift
//  FaceIt
//
//  Created by Anton on 22.06.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit

class FaceViewController: UIViewController {
    
    @IBOutlet weak var faceView: FaceView!  {
        didSet {
            let hadler = #selector(FaceView.changeScale(byReactingTo:))
            let pinchRecognizer = UIPinchGestureRecognizer(target: faceView, action: hadler)
            faceView.addGestureRecognizer(pinchRecognizer)
            
//            let hadlerTap = #selector(self.eyesInteraction(byReactingTo:))
//            let tapRecognizer = UITapGestureRecognizer(target: self, action: hadlerTap)
//            tapRecognizer.numberOfTapsRequired = 1
//            faceView.addGestureRecognizer(tapRecognizer)
            
            let hadlerSwipeUp = #selector(self.mouthInteraction(byReactingTo:))
            let swipeRecognizerUp = UISwipeGestureRecognizer(target: self, action: hadlerSwipeUp)
            swipeRecognizerUp.direction = .up
            faceView.addGestureRecognizer(swipeRecognizerUp)
            let swipeRecognizerDown = UISwipeGestureRecognizer(target: self, action: hadlerSwipeUp)
            swipeRecognizerDown.direction = .down
            faceView.addGestureRecognizer(swipeRecognizerDown)
            updateUI()
        }
    }
    
    private struct HeadShake {
        static let angle = CGFloat.pi/6
        static let segmentDuration: TimeInterval = 0.5
    }
    
    private func rotateFace(by angle: CGFloat) {
        faceView.transform = faceView.transform.rotated(by: angle)
    }
    
    private func shakeHead() {
        UIView.animate(
            withDuration: HeadShake.segmentDuration,
            animations: { self.rotateFace(by: HeadShake.angle)},
            completion: {finished in
                if finished {
                    UIView.animate(
                        withDuration: HeadShake.segmentDuration,
                        animations: { self.rotateFace(by: -HeadShake.angle*2)},
                        completion: { finished in
                            UIView.animate(
                                withDuration: HeadShake.segmentDuration,
                                animations: {self.rotateFace(by: HeadShake.angle)})
                    })
                }
        })
    }
    
    @IBAction func shakeHead(_ sender: UITapGestureRecognizer) {
        shakeHead()
    }
    var expression = FacialExpression(eyes: .open, mouth: .grin) {
        didSet {
            updateUI()
        }
    }
    
    func eyesInteraction(byReactingTo tapRecognizer: UITapGestureRecognizer) {
        if tapRecognizer.state == .ended {
            expression = FacialExpression(eyes: faceView.eyesOpen ? .closed : .open, mouth: expression.mouth)
        }
    }
    
    func mouthInteraction(byReactingTo swipeRecognizer: UISwipeGestureRecognizer) {
        switch swipeRecognizer.direction {
        case UISwipeGestureRecognizerDirection.up:
            expression = expression.sadder
        case UISwipeGestureRecognizerDirection.down:
            expression = expression.happier
        default:
            break
        }
    }
    
    private func updateUI() {
        switch expression.eyes {
        case .open:
            faceView?.eyesOpen = true
        case .closed:
            faceView?.eyesOpen = false
        case .squinting:
            faceView?.eyesOpen = false
            
        }
        faceView?.mouthCurvature = mouthCurvatures[expression.mouth] ?? 0.0
    }
    
    private let mouthCurvatures = [FacialExpression.Mouth.grin:0.5,
                                   .frown:-1.0,
                                   .smile:1.0,
                                   .neutral:0.0,
                                   .smirk:-0.5]
    
}

