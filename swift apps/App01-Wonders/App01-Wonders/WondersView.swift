//  Created by Valeria Conde on 18/08/21.
//

import SwiftUI

struct WondersView: View {
    
    @StateObject var wonder = WonderModel()
    
    var body: some View {
        
        NavigationView{
            ZStack {
                Color("pink") // cambia el color del fondo completo
                    .edgesIgnoringSafeArea(/*@START_MENU_TOKEN@*/.all/*@END_MENU_TOKEN@*/) // hace que suba todo el color de la pantalla hasta arriba (ej. iphone 10)
            
                VStack {
                    Text("7 mujeres que cambiaron el mundo")
                        .foregroundColor(Color(.white))
                        .font(.custom("Montserrat-Light", size:35))
                        .multilineTextAlignment(.center)
                        .padding() // pone espacios al rededor del hello world; si le pongo .leading, tamano es nada mas quiero padding del lado izquierdo, .trailing del lado derecho
                    
                    ScrollView(.vertical, showsIndicators: false) {
                        
                        VStack {
                            ForEach(wonder.wondersArr) { item in
                                VStack {
                                    NavigationLink(
                                        destination: WonderDetailView(wonder:item),
                                        label: {
                                            
                                            VStack {
                                                Image(item.imgArr[0])
                                                    .resizable()
                                                    .scaledToFit()
                                                    .frame(width:300)
                                                    .cornerRadius(15)
                                                
                                                Text(item.name)
                                                    .foregroundColor(Color(.white))
                                                    .font(.custom("Montserrat-Light", size: 20))
                                            }
                                        }
                                    )
                                }
                            }
                        }
                    }
                    Spacer()
                }
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        WondersView()
    }
}
