//
//  MovieCellView.swift
//  App05-Entrenimiento
//
//  Created by Valeria Conde on 9/5/21.
//

import SwiftUI

struct MovieCellView: View {
    let movie: Media
    
    var body: some View {
        Image(movie.arrImages[0])
            .resizable()
            .scaledToFit()
            .cornerRadius(3.0)
            .frame(height: 200)
            .shadow(radius: 10)
    }
}

struct MovieCellView_Previews: PreviewProvider {
    static var previews: some View {
        MovieCellView(movie: Media.defaultMedia)
    }
}
