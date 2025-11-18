TP mettant en oeuvre un condensateur chargé par un signal PWM.
La décharge est assurée par un transistor 2N2222 :
- Utilisation de la sortie Arduino PWM 3. Câblage d'une diode + résistance 10k + condensateur 1µF en série.
- Câblage en parallèle du condensateur d'une résistance 10 Ohms + transistor 2N2222
- Pilotage du transistor sur la sortie 2
- Acquisition de la charge du condensateur sur l'entrée A0

