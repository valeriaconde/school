//
//  MovieDetailView.swift
//  App05-Entrenimiento
//
//  Created by Valeria Conde on 9/5/21.
//

import SwiftUI

struct MovieDetailView: View {
    
    let movie: Media
    
    var body: some View {
        
        ScrollView {
            VStack {
                ZStack {
                    Image(movie.sLogo)
                        .resizable()
                        .scaledToFit()
                        .opacity(0.3)
                    
                    HStack {
                        Image(movie.arrImages[0])
                            .resizable()
                            .scaledToFit()
                            .frame(height:200)
                            .cornerRadius(/*@START_MENU_TOKEN@*/3.0/*@END_MENU_TOKEN@*/)
                        
                        VStack {
                            Text(movie.sName)
                                .font(.headline)
                            Text("\(String(movie.iYear))")
                                .font(.caption)
                        }
                    }
                }
                
                Text(movie.sOverview)
                    .multilineTextAlignment(.center)
                    .padding()
                
                TabView{
                    ForEach(movie.arrImages, id:\.self) { image in
                        Image(image)
                            .resizable()
                            .scaledToFit()
                            .frame(height:100)
                            .clipShape(Circle())
                    }
                }
                .tabViewStyle(PageTabViewStyle())
                
                VideoWebView(url: movie.sTrailer)
                    .frame(height: 300)
            }
            .padding()
        }
    }
}

struct MovieDetailView_Previews: PreviewProvider {
    static var previews: some View {
        MovieDetailView(movie: Media.defaultMedia)
    }
}
