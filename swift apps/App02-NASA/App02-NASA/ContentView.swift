//
//  ContentView.swift
//  App02-NASA
//
//  Created by Valeria Conde on 8/22/21.
//

// 1390420235602

import SwiftUI
import SDWebImageSwiftUI

struct ContentView: View {
    
    @State var photos = [PhotoInfo]()
    
    var body: some View {

        List(photos) { photo in
        
            VStack {
                Text(photo.title)
                AnimatedImage(url: photo.url)
                    .resizable()
                    .scaledToFit()
                    .frame(width: 300)
            }
        
        } // List
        .onAppear() {
            PhotoModel().loadData() { (photos) in
                self.photos = photos
            }
        }
        
        
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
