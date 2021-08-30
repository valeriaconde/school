//
//  ListaTareasView.swift
//  App08-Tareas
//
//  Created by Valeria Conde on 8/29/21.
//

import SwiftUI
import CoreData

struct ListaTareasView: View {
    
    @Environment(\.managedObjectContext) var viewContext

        @FetchRequest(entity: Actividad.entity(), sortDescriptors: [NSSortDescriptor(keyPath: \Actividad.fechaFin, ascending: false)], predicate: NSPredicate(format: "terminada = %d", false), animation: .default)

           var fetchedItems: FetchedResults<Actividad>
    
    var body: some View {
        NavigationView{
            List {
                ForEach(fetchedItems, id:\.self) { item in
                    NavigationLink(destination: NuevaTareaView(tituloActividad: item.titulo!, fechaFin: item.fechaFin!, prioridad: item.prioridad!, terminada: item.terminada, nuevaActividad: false, actividad: item)) {
                            Text(item.titulo!)
                    }
                }
                .onDelete(perform: borrarDatos)
                Text("Actividad")
            }
            .toolbar{
                HStack{
                    EditButton()
                    NavigationLink(destination: NuevaTareaView(actividad: Actividad())) {
                        Label("Add Entry", systemImage: "plus")

                    }
                }
            }
            .navigationBarTitle("Tareas", displayMode: .inline)
        }
        
    }
    
    func guardarDatos(){
                
        let newItem = Actividad(context: viewContext)
        newItem.titulo = "Actividad"
        newItem.fechaFin = Date()
        newItem.terminada = false
        newItem.prioridad = "Normal"
    do {
            try viewContext.save()
        } catch {
            print(error.localizedDescription)
        }
    }
    
    func borrarDatos(at offsets: IndexSet) {
            for index in offsets {
                let item = fetchedItems[index]
                viewContext.delete(item)
            }
            do {
                try viewContext.save()
            } catch {
                print(error.localizedDescription)
            }
        }
    
}

struct ListaTareasView_Previews: PreviewProvider {
    static var previews: some View {
        ListaTareasView()
    }
}
