//
//  NuevaTareaView.swift
//  App08-Tareas
//
//  Created by Valeria Conde on 8/29/21.
//

import SwiftUI

struct NuevaTareaView: View {
    @Environment(\.managedObjectContext) var viewContext
    @Environment(\.presentationMode) var presentationMode
    
    @State var tituloActividad = ""
    @State var fechaFin = Date()
    @State var prioridad = "Normal"
    @State var terminada = false
    
    var nuevaActividad = true
    var actividad : Actividad
    
    let ListaPrioridad = ["Alta", "Normal", "Baja"]
    
    var body: some View {
        NavigationView {
            Form{
                Section(header: Text("Detalle tarea")) {
                    TextField("Titulo", text: $tituloActividad)
                    DatePicker("Fecha", selection: $fechaFin, displayedComponents: .date)
                }
                Section(header: Text("Prioridad")) {
                    Picker("Prioridad", selection: $prioridad) {
                        ForEach(ListaPrioridad, id:\.self){
                            Text($0)
                        }
                    }
                    .pickerStyle(SegmentedPickerStyle())
                }
                Section() {
                    Toggle(isOn: $terminada) {
                        Text("Tarea terminada")
                    }
                }
                Button(action: {
                    guardarDatos()
                    self.presentationMode.wrappedValue.dismiss()
                }) {
                    Text("Guardar tarea")
                }
            }
        }
    }
    
    func guardarDatos(){
       guard self.tituloActividad != "" else {
               return
       }
        
        if nuevaActividad {
           let newItem = Actividad(context: viewContext)
           newItem.titulo = tituloActividad
           newItem.fechaFin = fechaFin
           newItem.terminada = terminada
           newItem.prioridad = prioridad
        } else {
            actividad.titulo = tituloActividad
            actividad.fechaFin = fechaFin
            actividad.terminada = terminada
            actividad.prioridad = prioridad
        }
        
   do {
           try viewContext.save()
       } catch {
           print(error.localizedDescription)
       }
    }
}

struct NuevaTareaView_Previews: PreviewProvider {
    static var previews: some View {
        NuevaTareaView(actividad: Actividad())
    }
}
