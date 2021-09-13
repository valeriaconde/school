//
//  MediaModel.swift
//  App04-Peliculas
//
//  Created by Elvia Rosas on 16/03/21.
//

    import SwiftUI

    class MediaModel: ObservableObject {
        
        @Published var arrMovies = [Media]()
        @Published var arrSeries = [Media]()
        
        
        init() {
            LoadInfo()
        }
        
        func LoadInfo() {
            
            var media: Media
            
            
            media = Media(sName: "Raya and the Last Dragon", iYear: 2021, rated: .PG, sGenre: "Animation, Adventure, Fantasy, Family, Action", sDuration: "1h 47m", sHeadline: "A quest to save her world.", sOverview: "Long ago, in the fantasy world of Kumandra, humans and dragons lived together in harmony. But when an evil force threatened the land, the dragons sacrificed themselves to save humanity. Now, 500 years later, that same evil has returned ...", dScore: 85, arrImages: ["Raya1","Raya2","Raya3","Raya4","Raya5"], sLogo: "RayaLogo", sTrailer: "https://www.youtube.com/embed/1VIZ89FEjYI")
            arrMovies.append(media)
            media = Media(sName: "Monster Hunter", iYear: 2020, rated: .PG13, sGenre: "Fantasy, Action, Adventure", sDuration: "1h 44m", sHeadline: "Behind our world, there is another.", sOverview: "A portal transports Cpt. Artemis and an elite unit of soldiers to a strange world where powerful monsters rule with deadly ferocity. Faced with relentless danger, the team encounters a mysterious hunter who may be their only hope to find a way home.", dScore: 73, arrImages: ["MonsterHunter1","MonsterHunter2","MonsterHunter3","MonsterHunter4","MonsterHunter5"], sLogo: "MonsterHunterLogo", sTrailer: "https://youtu.be/3od-kQMTZ9M")
            arrMovies.append(media)
            media = Media(sName: "Wonder Woman 1984", iYear: 2020, rated: .B, sGenre: "Fantasy, Action, Adventure", sDuration: "2h 32m", sHeadline: "A new era of wonder begins.", sOverview: "Wonder Woman comes into conflict with the Soviet Union during the Cold War in the 1980s and finds a formidable foe by the name of the Cheetah.", dScore: 69, arrImages: ["WonderWoman1","WonderWoman2","WonderWoman3","WonderWoman4","WonderWoman5"], sLogo: "WonderWomanLogo", sTrailer: "https://youtu.be/sfM7_JLk-84")
            arrMovies.append(media)
            media = Media(sName: "Cobra Kai ", iYear: 2018, rated: .TV14, sGenre: "Action & Adventure, Drama", sDuration: "30m", sHeadline: "Cobra Kai never dies", sOverview: "This Karate Kid sequel series picks up 30 years after the events of the 1984 All Valley Karate Tournament and finds Johnny Lawrence on the hunt for redemption by reopening the infamous Cobra Kai karate dojo. This reignites his old rivalry with the successful Daniel LaRusso, who has been working to maintain the balance in his life without mentor Mr. Miyagi.", dScore: 81, arrImages: ["CobraKai1","CobraKai2","CobraKai3","CobraKai4","CobraKai5"], sLogo: "CobraKaiLogo", sTrailer: "https://www.youtube.com/watch?v=xCwwxNbtK6Y")
            arrSeries.append(media)
            media = Media(sName: "WandaVision", iYear: 2021, rated: .TV14, sGenre: "Sci-Fi & Fantasy, Mystery, Drama", sDuration: "36m", sHeadline: "Cobra Kai never dies.", sOverview: "Wanda Maximoff and Vision—two super-powered beings living idealized suburban lives—begin to suspect that everything is not as it seems.", dScore: 85, arrImages: ["WandaVision1","WandaVision2","WandaVision3","WandaVision4","WandaVision5"], sLogo: "WandaVision2", sTrailer: "https://youtu.be/sj9J2ecsSpo")
            arrSeries.append(media)
            media = Media(sName: "The Mandalorian", iYear: 2019, rated: .TV14, sGenre: "Sci-Fi & Fantasy, Action & Adventure, Western, Drama", sDuration: "35m", sHeadline: "Bounty hunting is a complicated profession.", sOverview: "After the fall of the Galactic Empire, lawlessness has spread throughout the galaxy. A lone gunfighter makes his way through the outer reaches, earning his keep as a bounty hunter.", dScore: 85, arrImages: ["TheMandalorian1","TheMandalorian2","TheMandalorian3","TheMandalorian4","TheMandalorian5"], sLogo: "TheMandalorianLogo", sTrailer: "https://youtu.be/eW7Twd85m2g")
            arrSeries.append(media)
        }
    
}
