//
//  TweetDetailsTableViewController.swift
//  Smashtag
//
//  Created by Anton on 23.08.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit
import Twitter

class TweetDetailsTableViewController: UITableViewController {
    
    private let DEFAULT_CELL_HEIGHT: CGFloat = 64
    var tweet: Twitter.Tweet?
    override func viewDidLoad() {
        super.viewDidLoad()
        self.tableView.estimatedRowHeight = DEFAULT_CELL_HEIGHT
        self.tableView.rowHeight = UITableViewAutomaticDimension
        
        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false
        
        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: - Table view data source
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        // #warning Incomplete implementation, return the number of sections
        return 4
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // #warning Incomplete implementation, return the number of rows
        
        if section == 0 {
            return tweet?.media.count ?? 0
        } else if section == 1 {
            return tweet?.hashtags.count ?? 0
        } else if section == 2 {
            return tweet?.userMentions.count ?? 0
        } else if section == 3 {
            return tweet?.urls.count ?? 0
        }
        return 0
    }
    
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        // Configure the cell...
        let cell:  UITableViewCell?
        if indexPath.section == 0 {
            print("-------------------------------------------------------------")
            cell = tableView.dequeueReusableCell(withIdentifier: "ImageInTweet", for: indexPath)
            if let customCell = cell as? ImageInTweetTableViewCell {
                let url = URL(string: tweet?.media[indexPath.row].url.absoluteString ?? "")
                let data = try? Data(contentsOf: url!) //make sure your image in this url does exist, otherwise unwrap in a if let check / try-catch
                customCell.tweetImage.image = UIImage(data: data!)
                return customCell
            }
        } else if indexPath.section == 3 {
            cell = tableView.dequeueReusableCell(withIdentifier: "URL", for: indexPath)
        } else {
            cell = tableView.dequeueReusableCell(withIdentifier: "TagsUsers", for: indexPath)
        }
            var textForLabel: String = ""
            if indexPath.section == 1 {
                textForLabel = tweet?.hashtags[indexPath.row].keyword ?? ""
                //add segue
                cell?.accessoryType = UITableViewCellAccessoryType.disclosureIndicator
            } else if indexPath.section == 2 {
                textForLabel = tweet?.userMentions[indexPath.row].keyword ?? ""
                //add segue
            } else if indexPath.section == 3 {
                textForLabel = tweet?.urls[indexPath.row].keyword ?? ""
            }
            cell?.textLabel?.text = textForLabel
        
        return cell!
    }
    
    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        if indexPath.section == 0 {
            let aspRatio = tweet?.media[indexPath.row].aspectRatio
            if aspRatio != nil, aspRatio! != 0 {
                let result = self.tableView.contentSize.width / CGFloat(aspRatio!)
                return result
            }
        }
        return DEFAULT_CELL_HEIGHT
    }
    
    
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        if section == 0, (tweet?.media.count)! > 0 {
            return "Images"
        } else if section == 1, (tweet?.hashtags.count)! > 0 {
            return "Hashtags"
        } else if section == 2, (tweet?.userMentions.count)! > 0 {
            return "Users"
        } else if section == 3, (tweet?.urls.count)! > 0 {
            return "URLs"
        }
        return ""
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "HashTagSegue" {
            if let receiver = segue.destination as? SmashTweetTableViewController {
                if let caller = sender as? TweetTagsUsersURLsTableViewCell {
                    let txt = caller.textLabel?.text
                    receiver.searchText = caller.textLabel?.text ?? ""
                    print("")
                }
            }
        } else if segue.identifier == "FullSizeImageSegue" {
            if let receiver = segue.destination as? FullSizeImageViewController {
                let caller = sender as? ImageInTweetTableViewCell
                let url = URL(string: tweet?.media[(caller?.tag)!].url.absoluteString ?? "")
                //let data = try? Data(contentsOf: url!) //make sure your image in this url does exist, otherwise unwrap in a if let check / try-catch
                //receiver.fullSizeImage?.image = UIImage(data: data!)
                receiver.urlToImage = url
            }
            
        }
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        if indexPath.section == 3 {
            let url = URL(string: tweet?.urls[indexPath.row].keyword ?? "")
            UIApplication.shared.open(url!)
        }
    }
    
    /*
     // Override to support conditional editing of the table view.
     override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
     // Return false if you do not want the specified item to be editable.
     return true
     }
     */
    
    /*
     // Override to support editing the table view.
     override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
     if editingStyle == .delete {
     // Delete the row from the data source
     tableView.deleteRows(at: [indexPath], with: .fade)
     } else if editingStyle == .insert {
     // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
     }
     }
     */
    
    /*
     // Override to support rearranging the table view.
     override func tableView(_ tableView: UITableView, moveRowAt fromIndexPath: IndexPath, to: IndexPath) {
     
     }
     */
    
    /*
     // Override to support conditional rearranging of the table view.
     override func tableView(_ tableView: UITableView, canMoveRowAt indexPath: IndexPath) -> Bool {
     // Return false if you do not want the item to be re-orderable.
     return true
     }
     */
    
    /*
     // MARK: - Navigation
     
     // In a storyboard-based application, you will often want to do a little preparation before navigation
     override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
     // Get the new view controller using segue.destinationViewController.
     // Pass the selected object to the new view controller.
     }
     */
    
}
