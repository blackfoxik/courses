//
//  FullSizeImageViewController.swift
//  Smashtag
//
//  Created by Anton on 26.08.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit

class FullSizeImageViewController: UIViewController, UIScrollViewDelegate {
    
    @IBOutlet weak var spinnerImageDownloading: UIActivityIndicatorView!
    @IBOutlet weak var scrollFullSizeImage: UIScrollView!
    @IBOutlet weak var fullSizeImage: UIImageView!
    var urlToImage: URL?
    override func viewDidLoad() {
        super.viewDidLoad()
        spinnerImageDownloading.startAnimating()
        if urlToImage != nil {
            //add to background task and add spinner
            //add to queue
            let queue = DispatchQueue.global(qos: .utility)
            queue.async {
                if let data = try? Data(contentsOf: self.urlToImage!) {//make sure your image in this url does exist, otherwise unwrap in a if let check / try-catch
                    DispatchQueue.main.async {
                        self.fullSizeImage?.image = UIImage(data: data)
                        self.scrollFullSizeImage.contentSize = (self.fullSizeImage.image?.size)!
                        self.scrollFullSizeImage.maximumZoomScale = 2
                        self.scrollFullSizeImage.minimumZoomScale = 0.5
                        self.scrollFullSizeImage.delegate = self
                        self.spinnerImageDownloading.stopAnimating()
                    }
                }
            }

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
