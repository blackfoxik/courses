//
//  RecentSearchsTableViewController.swift
//  Smashtag
//
//  Created by Anton on 28.08.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit
import CoreData

class RecentSearchsTableViewController: UITableViewController {
    
    var searches: [NSManagedObject]?
    var indicator = UIActivityIndicatorView()
    var container: NSPersistentContainer? = (UIApplication.shared.delegate as? AppDelegate)?.persistentContainer
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false
        
        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem()
    }
    override func viewWillAppear(_ animated: Bool) {
        fillSearches()
    }
    private func fillSearches() {
        indicator = UIActivityIndicatorView(frame: CGRect(x: 0, y: 0, width: 40, height: 40))
        indicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyle.gray
        indicator.center = self.view.center
        self.view.addSubview(indicator)
        indicator.startAnimating()
        let queue = DispatchQueue.global(qos: .userInteractive)
        queue.async {
            self.searches = [NSManagedObject]()
            //get from persistent container
            let fetchRequest = NSFetchRequest<NSManagedObject>(entityName: "Search")
            let sortDescriptor = NSSortDescriptor(key: "date", ascending: false)
            fetchRequest.sortDescriptors = [sortDescriptor]
            do {
                self.searches = try self.container?.viewContext.fetch(fetchRequest)
            } catch let error as NSError {
                print("Could not fetch.\(error), \(error.userInfo)")
            }
            DispatchQueue.main.async {
                self.tableView.reloadData()
                self.indicator.stopAnimating()
            }
        }
        
        
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: - Table view data source
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        // #warning Incomplete implementation, return the number of sections
        return 1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // #warning Incomplete implementation, return the number of rows
        return searches?.count ?? 0
    }
    
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "searchCell", for: indexPath)
        
        // Configure the cell...
        let search = searches?[indexPath.row]
        cell.textLabel?.text = search?.value(forKey: "text") as? String
        
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
        
        let myString = formatter.string(from: (search?.value(forKey: "date") as? Date)!)
        cell.detailTextLabel?.text = myString
        return cell
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "RecentSearchSegue" {
            if let receiver = segue.destination as? SmashTweetTableViewController {
                if let caller = sender as? UITableViewCell {
                    receiver.searchText = caller.textLabel?.text ?? ""
                }
            }
        }
        if segue.identifier == "PopularTagsUsers" {
            if let receiver = segue.destination as? PopularMentionsTableViewController {
                if let caller = sender as? UITableViewCell {
                  receiver.title = "popular mentions for \(caller.textLabel?.text ?? "")"
                  receiver.searchTerm = caller.textLabel?.text
                }
            }
            
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
