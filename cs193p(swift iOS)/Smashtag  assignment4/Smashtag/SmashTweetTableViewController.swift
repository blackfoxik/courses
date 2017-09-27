//
//  SmashTweetTableViewController.swift
//  Smashtag
//
//  Created by Anton on 16.08.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import UIKit
import Twitter
import CoreData

class SmashTweetTableViewController: TweetTableViewController {
    
    var container: NSPersistentContainer? = (UIApplication.shared.delegate as? AppDelegate)?.persistentContainer
    let COUNT_OF_SEARCHES_FOR_TRACKING: Int = 5
    
    override func insertTweets(_ newTweets: [Twitter.Tweet]) {
        super.insertTweets(newTweets)
        updateDatabase(with: newTweets)
        saveSearch()
    }
    
    
    private func updateDatabase(with tweets: [Twitter.Tweet]) {
        print("starting database load")
        container?.performBackgroundTask {[weak self] context in
            for twitterInfo in tweets {
                _ = try? Tweet.findOrCreateTweet(matching: twitterInfo, in: context)
            }
            try? context.save()
            print("done database loading")
            self?.printDatabaseStatistics()
        }
        
    }
    private func printDatabaseStatistics() {
        if let context = container?.viewContext {
            context.perform {
                let request: NSFetchRequest<Tweet> = Tweet.fetchRequest()
                if let tweetCount = (try? context.fetch(request))?.count {
                    print("\(tweetCount) tweets")
                    
                }
                if let tweeterCount = try? context.count(for: TwitterUser.fetchRequest()) {
                    print("\(tweeterCount) Twitter users")
                }
            }
        }
        
    }
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "Tweeters Mentioning Search Term" {
            if let tweetersTVC = segue.destination as? SmashTweetersTableViewController {
                tweetersTVC.mention = searchText
                tweetersTVC.container = container
            }
        }
        if segue.identifier == "tweetDetailsSegue" {
            if let tweetDetails = segue.destination as? TweetDetailsTableViewController {
                if let tweetTableCell = sender as? TweetTableViewCell {
                    tweetDetails.tweet = tweetTableCell.tweet
                    tweetDetails.title = tweetTableCell.tweet?.user.name
                }
            }
        }
    }
}

private extension SmashTweetTableViewController {
    func saveSearch() {
        let searchText: String = super.searchText ?? ""
        print("-------------------------------------------------------------")
        print(searchText)
        if searchText != "" {
            if itemWasUpdatedWithCurrentDateWhichWasFoundBy(searchText) {
                return
            }
            deleteOldestItemIfCountEqualOrBiggerCOUNT_OF_SEARCHES_FOR_TRACKING()
            createAndSafeNewSearchWith(searchText)
        }
    }
    
    private func createAndSafeNewSearchWith(_ searchText: String) {
        let managedContext = container?.viewContext
        let entity = NSEntityDescription.entity(forEntityName: "Search", in: managedContext!)
        let search = NSManagedObject(entity: entity!, insertInto: managedContext)
        search.setValue(searchText, forKey: "text")
        search.setValue(Date(), forKey: "date")
        do {
            try managedContext?.save()
            
        } catch let error as NSError {
            print("Could not save search. \(error), \(error.userInfo)")
        }
    }

    
    private func deleteOldestItemIfCountEqualOrBiggerCOUNT_OF_SEARCHES_FOR_TRACKING() {
        let managedContext = container?.viewContext
        let fetchRequest = NSFetchRequest<NSManagedObject>(entityName: "Search")
        let sortDescriptor = NSSortDescriptor(key: "date", ascending: true)
        fetchRequest.sortDescriptors = [sortDescriptor]
        do {
            let searches = try container?.viewContext.fetch(fetchRequest)
            if searches?.count ?? 0  >= COUNT_OF_SEARCHES_FOR_TRACKING {
                //find oldest and delete
                managedContext?.delete((searches?.first)!)
                try managedContext?.save()
            }
        } catch let error as NSError {
            print("Could not fetch.\(error), \(error.userInfo)")
        }
    }
    
    private func itemWasUpdatedWithCurrentDateWhichWasFoundBy(_ searchText: String) -> Bool {
        let managedContext = container?.viewContext
        //try to find in existed and update if exists
        let fetchRequest = NSFetchRequest<NSManagedObject>(entityName: "Search")
        fetchRequest.predicate = NSPredicate(format: "text==%@", searchText)
        do {
            let searches = try container?.viewContext.fetch(fetchRequest)
            if searches?.count ?? 0 > 0 {
                //update object and return
                let search = searches?[0]
                search?.setValue(Date(), forKey: "date")
                //save
                try managedContext?.save()
                return true
            } else {
                return false
            }
        } catch let error as NSError {
            print("Could not fetch.\(error), \(error.userInfo)")
        }
        return false
    }
    
    
    
//     func saveSearch() {
//        let searchText: String = super.searchText ?? ""
//        print("-------------------------------------------------------------")
//        print(searchText)
//        if searchText != "" {
//            let managedContext = container?.viewContext
//            //try to find in existed and update if exists
//            var fetchRequest = NSFetchRequest<NSManagedObject>(entityName: "Search")
//            fetchRequest.predicate = NSPredicate(format: "text==%@", searchText)
//            do {
//                let searches = try container?.viewContext.fetch(fetchRequest)
//                if searches?.count ?? 0 > 0 {
//                    //update object and return
//                    let search = searches?[0]
//                    search?.setValue(Date(), forKey: "date")
//                    //save
//                    try managedContext?.save()
//                    return
//                }
//            } catch let error as NSError {
//                print("Could not fetch.\(error), \(error.userInfo)")
//            }
//            //
//            fetchRequest = NSFetchRequest<NSManagedObject>(entityName: "Search")
//            let sortDescriptor = NSSortDescriptor(key: "date", ascending: true)
//            fetchRequest.sortDescriptors = [sortDescriptor]
//            do {
//                let searches = try container?.viewContext.fetch(fetchRequest)
//                if searches?.count ?? 0  >= COUNT_OF_SEARCHES_FOR_TRACKING {
//                    //find oldest and delete
//                    managedContext?.delete((searches?.first)!)
//                }
//            } catch let error as NSError {
//                print("Could not fetch.\(error), \(error.userInfo)")
//            }
//            
//            
//            let entity = NSEntityDescription.entity(forEntityName: "Search", in: managedContext!)
//            let search = NSManagedObject(entity: entity!, insertInto: managedContext)
//            search.setValue(searchText, forKey: "text")
//            search.setValue(Date(), forKey: "date")
//            do {
//                try managedContext?.save()
//                
//            } catch let error as NSError {
//                print("Could not save search. \(error), \(error.userInfo)")
//            }
//        }
//    }
    
}
