//
//  Media.swift
//  App04-Peliculas
//
//  Created by Elvia Rosas on 16/03/21.
//

import SwiftUI

struct Media: Identifiable{
    
    var id = UUID()
    var sName: String
    var iYear: Int
    var rated : Rated
    var sGenre: String
    var sDuration: String
    var sHeadline: String
    var sOverview: String
    var dScore: Double
    var arrImages: [String]
    var sLogo: String
    var sTrailer: String
    
}

