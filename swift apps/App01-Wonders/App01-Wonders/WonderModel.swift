//
//  WonderModel.swift
//  App01-Wonders
//
//  Created by Valeria Conde on 18/08/21.
//

import SwiftUI

class WonderModel: ObservableObject {
    
    @Published var wondersArr = [Wonder]()
    
    init() {
        LoadInfo()
    }
    
    func LoadInfo() {
        var wonder: Wonder

        // Melinda
        wonder = Wonder(name:"Melinda Gates", description:"Es ingeniera en informática y conomía por la Universidad Duke. En el 2000 creó la organización de caridad Bill and Melinda Gates Foundation, la cual ha donado más de 38,000,000,000 de dólares. Trabaja para promover la equidad en áreas de salud y educación.\n", video:"https://www.youtube.com/watch?v=2BOTS9GAjc4", latitude:47.606209, longitude:-122.332069, imgArr:["melinda"])
        wondersArr.append(wonder);
        
        // Katelyn
        wonder = Wonder(name:"Katelyn Ohashi", description:"Es una gimnasta artística. En enero de 2019 obtuvo una calificación de 10 perfecta en la competencia de la NCAA. En 2018 alzó la voz contra los abusos de la federación de gimnasia estadounidense. Es promotora de la salud mental.\n", video:"https://www.youtube.com/watch?v=4ic7RNS4Dfo", latitude:47.606209, longitude:-122.332069, imgArr:["katelyn"])
        wondersArr.append(wonder);
        
        // Serena
        wonder = Wonder(name:"Serena Williams", description:"Es considerada como una de las mejores tenistas de la historia, campeona de 39 títulos en torneos Grand Slam. Ha reescrito las reglas del tenis para las mujeres y está comprometida con nunca dejar de luchar por la equidad.\n", video:"https://www.youtube.com/watch?v=WKndCCPtUqI", latitude:26.809790, longitude:-80.136307, imgArr:["serena"])
        wondersArr.append(wonder);

        // Katie
        wonder = Wonder(name:"Katie Bouman", description:"Es ingeniera eléctrica y de ciencias de la computación que trabaja en el campo de imágenes generadas por computadora. Dirigió el desarrollo de un algoritmo para la obtención de imágenes de agujeros negros y fue miembro del equipo Telescopio Event Horizon que capturó la primera imagen de un agujero negro.\n", video:"https://www.youtube.com/watch?v=BIvezCVcsYs", latitude:34.147785, longitude:-118.144516, imgArr:["katie"])
        wondersArr.append(wonder);
        
        // Yusra
        wonder = Wonder(name:"Yusra Mardini", description:"Yusra nació en Damasco, Siria, un país en guerra. El motor de la lancha de plástico que su familia utilizó para huir de la guerra se descompuso, y ella se encargó de empujar la lancha, nadando durante más de tres horas para llegar a la costa.En 2016 formó parte del primer equipo de refugiados de los juegos Olímpicos.\n", video:"https://www.youtube.com/watch?v=o5KAB_sWlm8", latitude:53.551086, longitude:9.993682, imgArr:["yusra"])
        wondersArr.append(wonder);

        // Ruth
        wonder = Wonder(name:"Ruth Bader Ginsburg", description:"Fue la segunda jueza de la Suprema Corte en la historia de los Estados Unidos. Le apasionaban los derechos de las mujeres y defendió seis casos emblemáticos sobre equidad de género. \"Si me preguntan cuándo habrá suficientes mujeres en la Suprema Corte, contestaré que cuando haya nueve\".\n", video:"https://www.youtube.com/watch?v=VRlEFT-44Ik", latitude:38.9071923, longitude:-77.0368707, imgArr:["ruth"])
        wondersArr.append(wonder);
        
        // Sheryl
        wonder = Wonder(name:"Sheryl Sandberg", description:"Es directora operativa de Facebook desde 2007. Escribió y fundó la organización Lean In, la cual lucha por la equidad de género.\n", video:"https://www.youtube.com/watch?v=18uDutylDa4&t=96s", latitude:37.453220, longitude:-122.183220, imgArr:["sheryl"])
        wondersArr.append(wonder);
    }
    
}


