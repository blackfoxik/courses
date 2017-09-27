//
//  GraphViewController.swift
//  Calculator
//
//  Created by Anton on 04.07.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit

class GraphViewController: UIViewController, UIGestureRecognizerDelegate, UIScrollViewDelegate, FuncDrawerDelegate  {
    
    private let WIDTH: CGFloat = 1024
    private let HEIGHT: CGFloat = 768
    private let OFFSET_THRESHOLD: CGFloat = 35
    var nScreenWidth: CGFloat?
    var nScreenHeight: CGFloat?
    //we use X as key Y as value in dictionary
    var storage: [CGFloat: CGFloat]?
    //use optional function
    var yForx: ((Double) -> Double?)?
    
    var textLabel: String?
    //@IBOutlet weak var Label: UILabel!
    
    @IBOutlet weak var graphView: GraphView! {
        didSet {
            let handler = #selector(GraphView.changeOriginOfTheGraph)
            let recognizer = UITapGestureRecognizer(target: graphView, action: handler)
            recognizer.numberOfTapsRequired = 2
            recognizer.delegate = self
            graphView.addGestureRecognizer(recognizer)
            graphView.setNeedsDisplay()
        }
    }
    
    @IBOutlet weak var scrollView: UIScrollView! {
        didSet {
            
            /*var graphViewManual = GraphView()
             
             let handler = #selector(GraphView.closePath)
             let recognizer = UITapGestureRecognizer(target: graphViewManual, action: handler)
             recognizer.numberOfTapsRequired = 2
             recognizer.delegate = self
             
             graphViewManual.addGestureRecognizer(recognizer)
             
             let handler2 = #selector(GraphView.myActionMethod(_:))
             let recognizer2 = UITapGestureRecognizer(target: graphViewManual, action: handler2)
             recognizer2.numberOfTapsRequired = 1
             recognizer2.delegate = self
             
             graphViewManual.addGestureRecognizer(recognizer2)
             graphViewManual.backgroundColor = UIColor.black*/
            //scrollView.addSubview(graphViewManual)
            
            /*scrollView.addSubview(graphView)
             scrollView.maximumZoomScale = 2.0
             scrollView.minimumZoomScale = 0.5
             scrollView.contentSize = CGSize(width: 1024, height: 768)
             scrollView.zoomScale = 1.0
             scrollView.delegate = self*/
            
            //let handlerZoom = #selector(viewForZoomingInScrollView(scrollView:))
            //let recognizerZoom = UIPinchGestureRecognizer(target: self, action: handlerZoom)
            //recognizerZoom.delegate = self
            //scrollView.addGestureRecognizer(recognizerZoom)
        }
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        //Label?.text = textLabel ?? ""
        //Label?.sizeToFit()
        
        
        /*if storage == nil {
         storage = [CGFloat]()
         let size: Int = Int(WIDTH * (nScreenWidth ?? 1))
         for x in 0..<size {
         var y: CGFloat
         y = CGFloat((x - size / 2) * 2)
         storage?.append(y)
         }
         }*/
    }
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        //Label?.text = "did app"
        //fill storage
        fillStorage()
        self.graphView.setNeedsDisplay()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        scrollView.maximumZoomScale = 5.0
        scrollView.minimumZoomScale = 0.5
        scrollView.contentSize = CGSize(width: WIDTH * (nScreenWidth ?? 1), height: HEIGHT * (nScreenHeight ?? 1))
        let cs = scrollView.contentSize
        scrollView.zoomScale = 1.0
        scrollView.delegate = self
    
        //work with delegate
        graphView?.delegate = self
        
        
        let handlerZoom = #selector(GraphView.changeAxesScale(_:))
        scrollView.pinchGestureRecognizer?.addTarget(self.graphView, action: handlerZoom)
        
        var curRect:CGRect = graphView.frame
        curRect.size.width = WIDTH * (nScreenWidth ?? 1)
        curRect.size.height = HEIGHT * (nScreenHeight ?? 1)
        graphView.frame = curRect
        //yForx = {cos (1 / ($0 + 2)) * $0}
        //yForx = {sin($0) / cos($0)}
    }
    
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        if (scrollView.contentOffset.x >= (scrollView.contentSize.width - scrollView.frame.size.width) + OFFSET_THRESHOLD ) || (scrollView.contentOffset.x < -OFFSET_THRESHOLD ){
            print("end of X right edge \(nScreenWidth ?? 1)")
            if nScreenWidth == nil {
                nScreenWidth = 2
            } else {
                nScreenWidth! += 1
            }
            var curRect:CGRect = graphView.frame
            curRect.size.width = WIDTH * (nScreenWidth ?? 1)
            curRect.size.height = HEIGHT * (nScreenHeight ?? 1)
            graphView.frame = curRect
            if (scrollView.contentOffset.x < -OFFSET_THRESHOLD ) {
                graphView.originOfTheGraph?.x = (graphView.originOfTheGraph?.x)! + WIDTH
            }
            scrollView.contentSize = CGSize(width: WIDTH * (nScreenWidth ?? 1), height: HEIGHT * (nScreenHeight ?? 1))
            fillStorage()
            graphView.setNeedsDisplay()
        }
        if (scrollView.contentOffset.y >= (scrollView.contentSize.height - scrollView.frame.size.height) + OFFSET_THRESHOLD ) || (scrollView.contentOffset.y < -OFFSET_THRESHOLD ){
            print("end of Y edge \(nScreenHeight ?? 1)")
            if nScreenHeight == nil {
                nScreenHeight = 2
            } else {
                nScreenHeight! += 1
            }
            var curRect:CGRect = graphView.frame
            curRect.size.width = WIDTH * (nScreenWidth ?? 1)
            curRect.size.height = HEIGHT * (nScreenHeight ?? 1)
            graphView.frame = curRect
            if (scrollView.contentOffset.y < -OFFSET_THRESHOLD ) {
                graphView.originOfTheGraph?.y = (graphView.originOfTheGraph?.y)! + HEIGHT
            }
            scrollView.contentSize = CGSize(width: WIDTH * (nScreenWidth ?? 1), height: HEIGHT * (nScreenHeight ?? 1))
            fillStorage()
            graphView.setNeedsDisplay()
        }
        
    }
    
    func getYForModelBy(_ pointXForModel: CGFloat) -> CGFloat {
        //At first we should try to find in model
        var y: CGFloat? = storage?[pointXForModel]
        if y != nil {
            return y!
        }
        //here we should call function that perform computation
        //return pointXForModel * 2
        let dX = Double(pointXForModel)
        y = CGFloat(yForx?(Double(pointXForModel)) ?? 0)
        return y!
    }
    
    func addXAndYIntoModel(_ pointXForModel: CGFloat, _ pointYForModel: CGFloat) {
        if storage == nil {
            storage = [CGFloat: CGFloat]()
        }
        storage?[pointXForModel] = pointYForModel
    }
    
    func fillStorage() {
        let pointsPerUnit = graphView.pointsPerUnit ?? graphView.DEFAULT_POINTS_PER_UNIT
        let origin: CGFloat = graphView.originOfTheGraph?.x ?? ((WIDTH * (nScreenWidth ?? 1)) / 2)
        let curWidth = WIDTH * (nScreenWidth ?? 1)
        let size: Int = Int(curWidth)
        let countOfUnits = size / (Int(pointsPerUnit))
        let leftEdge =  (0 - origin) / pointsPerUnit
        let rightEdge = (curWidth - origin) / pointsPerUnit
        for x in 0..<size {
            //1. make representation of X for model
            let pointXForModel = leftEdge + CGFloat(x) / pointsPerUnit
            //2. compute Y by X for model
            let pointYForModel = getYForModelBy(pointXForModel)
            //3. add current X and Y into model
            addXAndYIntoModel(pointXForModel, pointYForModel)
            //print("for X = \(pointXForModel) Y = \(pointYForModel)")
        }
        
    }
    
    
    func getYBy(_ x: Int) -> CGFloat? {
        let pointsPerUnit = graphView.pointsPerUnit ?? graphView.DEFAULT_POINTS_PER_UNIT
        let originX: CGFloat = graphView.originOfTheGraph?.x ?? ((WIDTH * (nScreenWidth ?? 1)) / 2)
        let originY: CGFloat = graphView.originOfTheGraph?.y ?? ((HEIGHT * (nScreenHeight ?? 1)) / 2)
        let curWidth = WIDTH * (nScreenWidth ?? 1)
        let size: Int = Int(curWidth)
        let countOfUnits = size / (Int(pointsPerUnit))
        let leftEdge =  (0 - originX) / pointsPerUnit
        let rightEdge = (curWidth - originX) / pointsPerUnit
        
        //1. make representation of X for model
        let pointXForModel = leftEdge + CGFloat(x) / pointsPerUnit
        //2. try to take Y from model by X
        var pointYForModel = storage?[pointXForModel]
        //3. convert model Y into view representation of Y
        var y: CGFloat?
        if pointYForModel != nil {
            if pointYForModel! < CGFloat(0) {
                pointYForModel = pointYForModel! * -1
                pointYForModel = pointsPerUnit * pointYForModel!
                y = originY + pointYForModel!
            } else {
                pointYForModel = pointsPerUnit * pointYForModel!
                y = originY - pointYForModel!
            }
        }
        return y
        //return storage?[x] ?? nil
        //return 0
    }
}
