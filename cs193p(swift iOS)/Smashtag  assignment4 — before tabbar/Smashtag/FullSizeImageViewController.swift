//
//  FullSizeImageViewController.swift
//  Smashtag
//
//  Created by Anton on 26.08.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit

class FullSizeImageViewController: UIViewController, UIScrollViewDelegate {
    
    @IBOutlet weak var scrollFullSizeImage: UIScrollView!
    @IBOutlet weak var fullSizeImage: UIImageView!
    var urlToImage: URL?
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if urlToImage != nil {
            //add to background task and add spinner
            let data = try? Data(contentsOf: urlToImage!) //make sure your image in this url does exist, otherwise unwrap in a if let check / try-catch
            fullSizeImage?.image = UIImage(data: data!)
            scrollFullSizeImage.contentSize = (fullSizeImage.image?.size)!
            scrollFullSizeImage.maximumZoomScale = 2
            scrollFullSizeImage.minimumZoomScale = 0.5
            scrollFullSizeImage.delegate = self
        }
        // Do any additional setup after loading the view.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func viewForZooming(in scrollView: UIScrollView) -> UIView? {
        return fullSizeImage
    }
    
    /*
     // MARK: - Navigation
     
     // In a storyboard-based application, you will often want to do a little preparation before navigation
     override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
     // Get the new view controller using segue.destinationViewController.
     // Pass the selected object to the new view controller.
     }
     */
    
}
