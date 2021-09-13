//
//  MoviesView.swift
//  App05-Entrenimiento
//
//  Created by Valeria Conde on 9/5/21.
//

import SwiftUI

struct MoviesView: View {
    
    @EnvironmentObject private var media : MediaModel

    var body: some View {
        ZStack {
            Color(.black)
                .ignoresSafeArea()
            
            ScrollView {
                VStack(alignment: .leading) {
                    ForEach(media.arrMovies) { movie in
                        NavigationLink(
                            destination: MovieDetailView(movie: movie),
                            label: {
                                MovieRowView(movie: movie)
                            })
                    }
                }
            }
            
        }
        .navigationBarTitleDisplayMode(.inline)
        .toolbar(content: {
            ToolbarItem(placement: .principal, content: {
                HStack{
                    Image("LaunchScreenImage")
                        .resizable()
                        .scaledToFit()
                        .frame(height: 20)
                    Text("Entretenimiento")
                        .foregroundColor(.white)
                }
            })
        })
        
    }
}

struct MoviesView_Previews: PreviewProvider {
    static var previews: some View {
        MoviesView()
    }
}
