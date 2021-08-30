//
//  PhotoInfo.swift
//  App02-NASA
//
//  Created by Valeria Conde on 8/22/21.
//

import Foundation

struct PhotoInfo: Decodable, Identifiable {
    var id = UUID()
    var title: String
    var description: String
    var url: URL
    
    enum CodingKeys: String, CodingKey {
        case title
        case description = "explanation"
        case url
    }
}
