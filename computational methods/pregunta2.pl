%Daniela Garza A00829404
%Valeria Conde A01281637

%A los fans de Girls Generation se les conoce como SONEs.
%Mientras que a los de Red Velvet les llaman Reveluvs.
%Y a los Blackpink se les llama Blinks.
%A todos los SONEs les gusta Red Velvet o Blackpink.
%Si les gusta Red Velvet, entonces le gustan las baladas.
%Si les gusta Blackpink, entonces les gusta el dance.
%Si les gusta la musica electronica y son SONEs, recomiendales DJ Hyo.
% La gente que disfruta el dance y las baladas, consideran a Chung Ha.
% como una buena recomendacion.
% Todos los SONEs a los que les gusta el drama, calificaron a Seohyun
% como una buena recomendacion.
% Taeyeon le interesa a todos los usuarios que gustan de baladas y son
% SONEs Si les gusta el drama y las baladas, es seguro que Heize les
% gustara.
%
/*CODIGOS
 *apodo_fan(*,X). --- *girlsgeneration, *red_velvet, *blackpink
 *le_gusta(X,Y,Z).
 *legustan(sones,baladas).
 *le_gustan(sones,dance).
 *se_recomienda(sones,dj_hyo).
 *recomendacion(dance,chung_ha).
 *buena_recomendacion(sones,seohyun).
 *le_interesan(sones,taeyeon).
 *le_gustaria(drama,heize).
 *gusto(fan,X,Y).
 *gustofan(X,Y,Z).
 *LeGustara(fan,taeyeon).
 */

fan(girlsgeneration).
fan(red_velvet).
fan(blackpink).

apodo_fan(girlsgeneration,sones).
apodo_fan(red_velvet,reveluvs).
apodo_fan(blackpink,blinks).

le_gusta(sones,red_velvet,blackpink).

%GUSTO DE BALADAS
%
%
le_gusta2(sones,red_velvet).
le_gusta2(red_velvet,baladas).
legustan(A,C) :- le_gusta2(A,B), le_gusta2(B,C).
%GUSTO DE DANCE
%
%
le_gusta3(sones,blackpink).
le_gusta3(blackpink,dance).
le_gustan(A,C) :- le_gusta3(A,B), le_gusta3(B,C).

%OTROS GUSTOS
%
%
le_gusta(blackpink,dance).
le_gusta(musica_electronica,dj_hyo).
%RECOMENDACIONES PARA SONEs
%
%
recomendar(sones,girlsgeneration).
recomendar(girlsgeneration,dj_hyo).
se_recomienda(A,C) :- recomendar(A,B), recomendar(B,C).
%GUSTO DE DANCE
%
%
disfruta(dance,baladas).
disfruta(baladas,chung_ha).
recomendacion(A,C) :- disfruta(A,B), disfruta(B,C).

les_gusta(sones,drama).
recomiendan(drama,seohyun).
le_interesa(baladas,taeyeon).

%RECOMENDACIONES DE DRAMA, BALADAS Y TAEYEON
%
%SEOHYUN
%
aquellosfans(sones,drama).
aquellosfans(drama,seohyun).
buena_recomendacion(A,C) :- aquellosfans(A,B), aquellosfans(B,C).
%TAEYEON
%
usuariosde(sones,baladas).
usuariosde(baladas,taeyeon).
le_interesan(A,C) :- usuariosde(A,B), usuariosde(B,C).
%HEIZE
%
si_les_gusta(drama,baladas).
si_les_gusta(baladas,heize).
le_gustaria(A,C) :- si_les_gusta(A,B), si_les_gusta(B,C).
%GUSTO DE NUEVO FAN
%
%
gusto(fan,girlsgeneration,reveluvs).
gustofan(sones,reveluvs,blinks).

gusto_fan(fan,girlsgeneration).
gusto_fan(girlsgeneration,reveluvs).
gusto_fan(reveluvs,baladas).
gusto_fan(baladas,taeyeon).

le_gustara(A,E) :- gusto_fan(A,B), gusto_fan(B,C), gusto_fan(C,D), gusto_fan(D,E).
