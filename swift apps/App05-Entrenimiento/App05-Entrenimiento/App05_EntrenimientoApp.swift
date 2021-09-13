//
//  App05_EntrenimientoApp.swift
//  App05-Entrenimiento
//
//  Created by Elvia Rosas on 30/08/21.
//

import SwiftUI

@main
struct App05_EntrenimientoApp: App {
    @StateObject var media = MediaModel()
    
    var body: some Scene {
        WindowGroup {
            MainView()
                .environmentObject(media)
        }
    }
}
