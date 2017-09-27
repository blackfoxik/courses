//
//  PopularMention+CoreDataProperties.swift
//  Smashtag
//
//  Created by Anton on 07.09.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import Foundation
import CoreData


extension PopularMention {

    @nonobjc public class func fetchRequest() -> NSFetchRequest<PopularMention> {
        return NSFetchRequest<PopularMention>(entityName: "PopularMention")
    }

    @NSManaged public var count: Int32
    @NSManaged public var text: String?
    @NSManaged public var search: NSSet?
    @NSManaged public var tweets: NSSet?

}

// MARK: Generated accessors for search
extension PopularMention {

    @objc(addSearchObject:)
    @NSManaged public func addToSearch(_ value: Search)

    @objc(removeSearchObject:)
    @NSManaged public func removeFromSearch(_ value: Search)

    @objc(addSearch:)
    @NSManaged public func addToSearch(_ values: NSSet)

    @objc(removeSearch:)
    @NSManaged public func removeFromSearch(_ values: NSSet)

}

// MARK: Generated accessors for tweets
extension PopularMention {

    @objc(addTweetsObject:)
    @NSManaged func addToTweets(_ value: Tweet)

    @objc(removeTweetsObject:)
    @NSManaged func removeFromTweets(_ value: Tweet)

    @objc(addTweets:)
    @NSManaged func addToTweets(_ values: NSSet)

    @objc(removeTweets:)
    @NSManaged func removeFromTweets(_ values: NSSet)

}
