//
//  Actividad+CoreDataProperties.swift
//  App08-Tareas
//
//  Created by Valeria Conde on 8/29/21.
//
//

import Foundation
import CoreData


extension Actividad {

    @nonobjc public class func fetchRequest() -> NSFetchRequest<Actividad> {
        return NSFetchRequest<Actividad>(entityName: "Actividad")
    }

    @NSManaged public var id: UUID?
    @NSManaged public var titulo: String?
    @NSManaged public var prioridad: String?
    @NSManaged public var fechaFin: Date?
    @NSManaged public var terminada: Bool

}

extension Actividad : Identifiable {

}
