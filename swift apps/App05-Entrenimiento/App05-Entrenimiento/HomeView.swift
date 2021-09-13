//
//  HomeView.swift
//  App05-Entrenimiento
//
//  Created by Elvia Rosas on 30/08/21.
//

import SwiftUI

struct HomeView: View {
    
    @EnvironmentObject private var media : MediaModel

    var body: some View {
        
        ZStack {
            Color(.black)
                .ignoresSafeArea()
            VStack{
                Text("Top Movies")
                    .font(.subheadline)
                    .foregroundColor(.white)
                
                ScrollView(.horizontal, showsIndicators: false){
                    HStack{
                        ForEach(media.arrMovies){ movie in
                            MovieCellView(movie: movie)
                        }
                    }
                }
                Spacer()
            } //VStack

        }//ZStack
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
        //.navigationBarTitle("Entretenimiento", displayMode: .inline)
    }
}

struct HomeView_Previews: PreviewProvider {
    static var previews: some View {
        HomeView()
            .environmentObject(MediaModel())
    }
}
