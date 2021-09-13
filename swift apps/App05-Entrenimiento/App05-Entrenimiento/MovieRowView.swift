//
//  MovieRowView.swift
//  App05-Entrenimiento
//
//  Created by Valeria Conde on 9/5/21.
//

import SwiftUI

struct MovieRowView: View {
    
    let movie: Media
    
    var body: some View {
        
        VStack {
            HStack {
                Image(movie.arrImages[0])
                    .resizable()
                    .scaledToFit()
                    .cornerRadius(3.0)
                    .frame(height: 100)
                
                VStack(alignment: .leading, spacing: 10) {
                    Text(movie.sName)
                        .font(.title2)
                    HStack {
                        Image(systemName: "star.fill")
                            .font(.caption)
                            .foregroundColor(.yellow)
                        Text("\(String(movie.dScore))")
                    }
                    Text("\(String(movie.iYear))")
                        .font(.caption)
                }
                Spacer()
            }
            .padding()
            Divider()
        }
    }
}

struct MovieRowView_Previews: PreviewProvider {
    static var previews: some View {
        MovieRowView(movie: Media.defaultMedia)
    }
}
