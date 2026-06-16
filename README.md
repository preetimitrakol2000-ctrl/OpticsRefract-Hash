# OpticsRefract-Hash

A lightweight, clean-room optics computation engine written in C99. This repository implements an open-addressed **Hash Table with Linear Probing** to look up refractive indices from material name strings, replacing slow conditional lookups with fast, constant-time evaluations.

## 📈 Functional Optimization Overview
* **Collision Resolution Strategy:** Open addressing via a linear probing search index.
* **Refraction Formula:** Snell's Law ($n_1 \sin(\theta_1) = n_2 \sin(\theta_2)$).
* **Average Time Complexity:** $O(1)$ constant-time lookup speed.
