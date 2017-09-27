//
//  PopularMention+CoreDataClass.swift
//  Smashtag
//
//  Created by Anton on 07.09.17.
//  Copyright © 2017 Anton. All rights reserved.
//

import Foundation
import CoreData

@objc(PopularMention)
public class PopularMention: NSManagedObject {
    class func findOrCreateMention(_ text: String, _ context: NSManagedObjectContext) throws -> PopularMention {
        let request: NSFetchRequest<PopularMention> = NSFetchRequest<PopularMention>(entityName: "PopularMention")
        request.predicate = NSPredicate(format: "text = %@", text)
        do {
            let result = try context.fetch(request)
            if result.count > 0 {
                return result[0]
            }
        } catch {
            throw error
        }
        let popularMention = PopularMention(context: context)
        popularMention.count = 1
        popularMention.text = text
        return popularMention
    }
    
}
