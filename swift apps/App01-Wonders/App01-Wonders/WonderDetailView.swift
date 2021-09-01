//
//  WonderDetailView.swift
//  App01-Wonders
//
//  Created by Valeria Conde on 18/08/21.
//

import SwiftUI

struct WonderDetailView: View {
    var wonder: Wonder
    
    var body: some View {
        VStack {
            MapView()
                .edgesIgnoringSafeArea(/*@START_MENU_TOKEN@*/.all/*@END_MENU_TOKEN@*/)
            
            Image(wonder.imgArr[0])
                .resizable()
                .scaledToFit()
                .frame(width: 250)
                .clipShape(Circle())
                .overlay(Circle().stroke(Color.white, lineWidth: 4))
                .shadow(radius: 7)
                .offset(y:-130)
                .padding(.bottom, -130)
            
            VStack {
                Text(wonder.name)
                    .font(.custom("Montserrat-Light", size: 24))
                    .padding()
                
                Text(wonder.description)
                    .multilineTextAlignment(.center)
                    .padding()
                
                NavigationLink(
                    destination: WebView(html: wonder.video),
                    label: {
                        Label("Video", systemImage: "play")
                    }
                )
                            
                Spacer()
            }
        }
    }
}

struct WonderDetailView_Previews: PreviewProvider {
    static var previews: some View {
        WonderDetailView(wonder: Wonder.defaultWonder)
    }
}
