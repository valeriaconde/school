//
//  App08_TareasApp.swift
//  App08-Tareas
//
//  Created by Valeria Conde on 8/26/21.
//

import SwiftUI
import CoreData

@main
struct App08_TareasApp: App {
    let persistenceController = PersistenceController.shared

    var body: some Scene {
        WindowGroup {
            //ContentView()
                ListaTareasView()
                .environment(\.managedObjectContext, persistenceController.container.viewContext)
        }
    }
}
