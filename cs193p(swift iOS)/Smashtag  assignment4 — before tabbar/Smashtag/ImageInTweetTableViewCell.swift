//
//  ImageInTweetTableViewCell.swift
//  Smashtag
//
//  Created by Anton on 23.08.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit

class ImageInTweetTableViewCell: UITableViewCell {

  
    @IBOutlet weak var tweetImage: UIImageView!
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
