//
//  VideoPlayerView.swift
//  App05-Entrenimiento
//
//  Created by Elvia Rosas on 02/09/21.
//

import AVKit
import SwiftUI

struct VideoPlayerView: View {
    
    let url : String
    
    var body: some View {
        VideoPlayer(player: AVPlayer(url: URL(string: url)!))

    }
}

struct VideoPlayerView_Previews: PreviewProvider {
    static var previews: some View {
        VideoPlayerView(url: "https://bit.ly/swswift")
    }
}
