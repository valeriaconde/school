//
//  Wonder.swift
//  App01-Wonders
//
//  Created by Valeria Conde on 18/08/21.
//

import SwiftUI

struct Wonder: Identifiable {

    var id = UUID()
    var name: String
    var description: String
    var video: String
    var latitude: Double
    var longitude: Double
    var imgArr: [String]

}
