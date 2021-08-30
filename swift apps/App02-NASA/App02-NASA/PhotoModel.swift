//
//  PhotoModel.swift
//  App02-NASA
//
//  Created by Valeria Conde on 8/22/21.
//

import Foundation

class PhotoModel: ObservableObject {
    @Published var photos = [PhotoInfo]()
    
    func loadData(completion:@escaping ([PhotoInfo]) -> ()) {
        // guard se asegura de que si es nula
        guard let url = URL(string:  "https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY&count=30") else { print("Invalid URL")
            return
        }
        
        URLSession.shared.dataTask(with: url) { data, response, error in
            let photos = try! JSONDecoder().decode([PhotoInfo].self, from:data!)
            print(photos) // apple maneja mucho concurrencia... eso causa problemas y para evitarlo usamos
            DispatchQueue.main.async {
                completion(photos)
            }
        }.resume()
        
    }

}
