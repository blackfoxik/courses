//
//  GraphView.swift
//  Calculator
//
//  Created by Anton on 14.07.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit

class GraphView: UIView {
    
    private var path: UIBezierPath?
    var axes: AxesDrawer?
    var pointsPerUnit : CGFloat?
    var DEFAULT_POINTS_PER_UNIT: CGFloat = 50
    let PACE_FOR_SCALING: CGFloat = 0.5
    var delegate: FuncDrawerDelegate?
    var originOfTheGraph: CGPoint? {
        didSet {
            delegate?.fillStorage()
            setNeedsDisplay()
        }
    }
    @IBOutlet weak var label:UILabel?

    
    func changeOriginOfTheGraph(_ sender: UITapGestureRecognizer) {
        if sender.state == .ended {
            originOfTheGraph = CGPoint(x: sender.location(in: self).x, y: sender.location(in: self).y)
        }
    }
    
    func changeAxesScale(_ sender: UIPinchGestureRecognizer) {
        if pointsPerUnit == nil {
            pointsPerUnit = DEFAULT_POINTS_PER_UNIT
        }
        if sender.scale > 1 {
            pointsPerUnit? += PACE_FOR_SCALING
        } else {
            if pointsPerUnit! > CGFloat(1) {
                pointsPerUnit? -= PACE_FOR_SCALING
            }
        }
        label?.adjustsFontSizeToFitWidth = true
        label?.text = String(describing: self.frame.size.width) + " x " + String(describing: self.frame.size.height) + " per unit:" + String(describing: self.frame.size.width / (pointsPerUnit ?? DEFAULT_POINTS_PER_UNIT))
        print("pinch was detected in GRAPHVIEW \(pointsPerUnit)")
        delegate?.fillStorage()
        setNeedsDisplay()
    }
    
    // Only override draw() if you perform custom drawing.
    // An empty implementation adversely affects performance during animation.
    override func draw(_ rect: CGRect) {
        // Drawing code
        //let csF = contentScaleFactor
        contentScaleFactor = 5
        axes = AxesDrawer()
        if originOfTheGraph == nil {
            originOfTheGraph = CGPoint(x: rect.origin.x + rect.width / 2, y: rect.origin.y + rect.height / 2)
        }
        axes?.drawAxes(in: rect, origin: originOfTheGraph!, pointsPerUnit: pointsPerUnit ?? DEFAULT_POINTS_PER_UNIT)
        path = nil
        let size: Int = Int(rect.size.width)
        for x in 0..<size {
            let y: CGFloat? = delegate?.getYBy(x)
            if y == nil {
                continue
            }

            let curPoint: CGPoint = CGPoint(x: CGFloat(x), y: y!)
            if path == nil {
                path = UIBezierPath()
                path?.move(to: curPoint)
            } else {
                path?.addLine(to: curPoint)
            }
        }
        path?.stroke()
        print("draw")
    }
    
}

protocol FuncDrawerDelegate {
    func fillStorage()
    func getYBy(_ x: Int) -> CGFloat?
}

