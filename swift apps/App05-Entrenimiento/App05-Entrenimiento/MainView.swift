//
//  ContentView.swift
//  App05-Entrenimiento
//
//  Created by Elvia Rosas on 30/08/21.
//

import SwiftUI

struct MainView: View {
    
    enum Tab {
        case home
        case movies
        case books
        case music
        case account
    }
    
    @State private var selection: Tab = .home
    
    init(){
        
        /*
        let navBarApperance = UINavigationBarAppearance()
        navBarApperance.titleTextAttributes = [.foregroundColor: UIColor.systemBackground]
        navBarApperance.largeTitleTextAttributes = [.foregroundColor: UIColor.systemBackground]
        navBarApperance.backgroundColor = UIColor.black
        navBarApperance.shadowColor = .clear
        UINavigationBar.appearance().standardAppearance = navBarApperance
        UINavigationBar.appearance().compactAppearance = navBarApperance
        UINavigationBar.appearance().scrollEdgeAppearance = navBarApperance
        UINavigationBar.appearance().tintColor = UIColor.systemPink
       
         
         
         let navBarApperance = UINavigationBarAppearance()
         navBarApperance.titleTextAttributes = [.foregroundColor: UIColor.systemPink]
         navBarApperance.largeTitleTextAttributes = [.foregroundColor: UIColor.systemPink]
         navBarApperance.backgroundColor = UIColor.black
         navBarApperance.shadowColor = .clear
         UINavigationBar.appearance().standardAppearance = navBarApperance
         UINavigationBar.appearance().compactAppearance = navBarApperance
         UINavigationBar.appearance().scrollEdgeAppearance = navBarApperance
         UINavigationBar.appearance().tintColor = UIColor.systemPink//UIColor.systemBackground
         
         
         */
        let tabBarAppearance = UITabBarAppearance()
        tabBarAppearance.backgroundColor = UIColor.black
        UITabBar.appearance().standardAppearance = tabBarAppearance
        
    }
    

    
    
    var body: some View {

        
        TabView(selection: $selection){
            NavigationView{
                HomeView()
            }
            .tabItem{
                let menuText = Text("Home", comment: "Home")
                Label{
                    menuText
                } icon: {
                    Image(systemName: "house")
                }
            }
            .tag(Tab.home)
            //.navigationViewStyle(StackNavigationViewStyle())
            .navigationAppearance(backgroundColor: .black, foregroundColor: .white, tintColor: .systemPink, hideSeparator: true)
                
            NavigationView{
                MoviesView()
            }
                .tabItem{
                    let menuText = Text("Movies", comment: "Movies")
                    Label{
                        menuText
                    } icon: {
                        Image(systemName: "film")
                    }
                }
                .tag(Tab.movies)
            
            NavigationView{
                Text("Books")
            }
                .tabItem{
                    let menuText = Text("Books", comment: "Books")
                    Label{
                        menuText
                    } icon: {
                        Image(systemName: "books.vertical")
                    }
                }
                .tag(Tab.books)
            
            NavigationView{
                Text("Music")
            }
                .tabItem{
                    let menuText = Text("Music", comment: "Music")
                    Label{
                        menuText
                    } icon: {
                        Image(systemName: "music.note.list")
                    }
                }
                .tag(Tab.music)
            
            NavigationView{
                Text("Account")
            }
                .tabItem{
                    let menuText = Text("Account", comment: "Account")
                    Label{
                        menuText
                    } icon: {
                        Image(systemName: "person.crop.circle")
                    }
                }
                .tag(Tab.account)
            
        }
        .accentColor(Color("LaunchScreenBackground"))
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        MainView()
    }
}
