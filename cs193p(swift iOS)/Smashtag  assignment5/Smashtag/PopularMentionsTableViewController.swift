//
//  PopularMentionsTableViewController.swift
//  Smashtag
//
//  Created by Anton on 08.09.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit
import CoreData

class PopularMentionsTableViewController: UITableViewController, NSFetchedResultsControllerDelegate {
    
    var searchTerm:String?
    
    var container: NSPersistentContainer? = (UIApplication.shared.delegate as? AppDelegate)?.persistentContainer
    
    var fetchedResultController: NSFetchedResultsController<PopularMention>!
    
    let POPULARITY_THRESHOLD: Int = 2
    
    //we use this array because we neew sort result in quite complicated way
    //of course we can use counter in PopularMention entity but it is also not so elegant
    var popularMentions: [PopularMention]?
    
    func initializeFetchedResultsController() {
        let request: NSFetchRequest<PopularMention> = PopularMention.fetchRequest()
        request.predicate = NSPredicate(format: "ANY search.text = %@ AND SUBQUERY(tweets, $t,  ANY $t.mentions = self).@count >= %d", searchTerm ?? "", POPULARITY_THRESHOLD)
        let sortDescriptor: NSSortDescriptor = NSSortDescriptor(key: "text", ascending: true)
        request.sortDescriptors = [sortDescriptor]
       
        
        fetchedResultController = NSFetchedResultsController(fetchRequest: request, managedObjectContext: (container?.viewContext)!, sectionNameKeyPath: nil, cacheName: nil)
        fetchedResultController.delegate = self
        do {
            try fetchedResultController.performFetch()
            //it is not elegant approach, but currently i cannot find a solution
            fillInnerArrayAndSortIt()
        } catch {
            fatalError("Failed to initialize FetchedResultController: \(error)")
        }

    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        //try? fillMentions()
        initializeFetchedResultsController()

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
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // #warning Incomplete implementation, return the number of rows
        return popularMentions?.count ?? 0
        //return fetchedResultController.fetchedObjects?.count ?? 0
    }

    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "PopularMentionCell", for: indexPath)
//        let mention =  fetchedResultController.object(at: indexPath)
//        cell.textLabel?.text = mention.text
//        cell.detailTextLabel?.text = "\(mention.tweets?.count ?? 0)"
        cell.textLabel?.text = popularMentions?[indexPath.row].text
        cell.detailTextLabel?.text = "\(popularMentions?[indexPath.row].tweets?.count ?? 0)"
        // Configure the cell...

        return cell
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "PopularSearchSegue" {
            if let receiver = segue.destination as? SmashTweetTableViewController {
                if let caller = sender as? UITableViewCell {
                    receiver.searchText = caller.textLabel?.text ?? ""
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

private extension PopularMentionsTableViewController {
    
    func fillInnerArrayAndSortIt() {
        popularMentions = fetchedResultController.fetchedObjects!
        popularMentions?.sort(by: {(s0: PopularMention, s1: PopularMention) ->Bool in
            if (s0.tweets?.count)! == (s1.tweets?.count)! {
                return s0.text! < s1.text!
            }
            return (s0.tweets?.count)! > (s1.tweets?.count)!
        })
    }
//using if we not use NSFetchedResultsControllerDelegate
//    func fillMentions() throws {
//        let request: NSFetchRequest<PopularMention> = PopularMention.fetchRequest()
//        //request.predicate = NSPredicate(format: "ANY search.text = %@", searchTerm ?? "")
//        //add conditionals
//        //more than 1 tweet
//        //request.predicate = NSPredicate(format: "ANY search.text = %@ AND SUBQUERY(tweets, $c, ANY $c.count >= %@).@count > 0", searchTerm ?? "", 2)
//        //let predicateSearch = NSPredicate(format: "ANY search.text = %@", searchTerm ?? "")
//        //let predicateTweets = NSPredicate(format: "ANY tweets.@count >= %@", 2)
//        //let predicateTweets = NSPredicate(format: "SUBQUERY(tweets).@count > 0")
//        //let compound = NSCompoundPredicate(andPredicateWithSubpredicates: [predicateSearch, predicateTweets])
//        //request.predicate = compound
//        //request.predicate = NSPredicate(format: "SUBQUERY(PopularMention, $p, ANY p.search.text = %@ AND ANY p.tweets.@count >= %d).@count > 0", searchTerm ?? "", 2)
//        
//        //work warriant
//        //request.predicate = NSPredicate(format: "ANY tweets.@count > %d AND SUBQUERY(search, $s, ANY search.text = %@).@count > 0", 2, searchTerm ?? "")
//        request.predicate = NSPredicate(format: "ANY search.text = %@ AND SUBQUERY(tweets, $t,  ANY $t.mentions = self).@count >= %d", searchTerm ?? "", POPULARITY_THRESHOLD)
//        
//        
//        //if two or more mentions with equal tweets they should appear in alphabetical order
//      
//        
////        let sortDescriptor = NSSortDescriptor(key: "tweets", ascending: false)
////        let sortDescriptors = [sortDescriptor]
////        request.sortDescriptors = sortDescriptors
//        do {
//            let result = try container?.viewContext.fetch(request)
//            
//            //result?.sort( {($0.tweets?.count)! > ($1.tweets?.count)!})
//            //result?.sort(by: {(s0: PopularMention, s1: PopularMention) -> Bool in
//             //   return s0.tweets?.count ?? 0 > s1.tweets?.count ?? 0})
//            popularMentions = result
//            //popularMentions?.sort(by: {($0.tweets?.count)! > ($1.tweets?.count)!})
//            popularMentions?.sort(by: {(s0: PopularMention, s1: PopularMention) ->Bool in
//                if (s0.tweets?.count)! == (s1.tweets?.count)! {
//                    return s0.text! < s1.text!
//                }
//                return (s0.tweets?.count)! > (s1.tweets?.count)!
//            })
//        } catch {
//            throw error
//        }
//    }
}
