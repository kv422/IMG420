# **Boids Flocking Game**

A simple **flocking simulation game** built in **Godot 4** with C#. Control a **Target** to avoid or interact with **Boids**, which move according to classic flocking rules. Includes **explosions on collision** and a **HUD** (not correctly implemented :( )to start and restart the game.  

---

## **Gameplay**

- Player controls the **Target** using **arrow keys**.  
- **Boids** move according to **Separation, Alignment, Cohesion, and Target-following rules**.  
- Colliding with a **Boid** triggers a **small explosion effect**.  
- **HUD** manages **Start Game** and **Try Again** buttons.  

---

## **Controls**

| **Action**      | **Key**        |
|-----------------|----------------|
| Move Up         | ↑ (Up Arrow)   |
| Move Down       | ↓ (Down Arrow) |
| Move Left       | ← (Left Arrow) |
| Move Right      | → (Right Arrow) |

---

## **Project Structure**


**Scripts:**

- **Boid.cs** — Controls individual **Boid** behavior (**flocking + collision**).  
- **Flock.cs** — Spawns and manages **Boids** in the scene.  
- **Target.cs** — Player-controlled object movement.  
- **HUD.cs** — Manages **Start** and **Try Again** buttons.  
- **Explosion.cs** — Handles **explosion effects**.  

---

## **Setup & Running**

1. Open the project in **Godot 4**.  
2. Ensure **BoidScene** is assigned in **Flock.tscn** or **Flock.cs** export.  
3. Assign **ExplosionScene** in the **Boid** node Inspector.  
4. Run **Main.tscn**.  
5. Press **Start Game** in the **HUD** to begin.  

---

## **Customization**

- **Number of Boids** — adjust in **Flock** node Inspector (**NumberOfBoids**).  
- **Boid speed & behavior** — adjust in **Boid** node Inspector:  
  - **MaxSpeed** — how fast **Boids** move  
  - **SeparationWeight** — how strongly **Boids** avoid each other  
  - **AlignmentWeight** — how strongly **Boids** align direction  
  - **CohesionWeight** — how strongly **Boids** move toward neighbors  
- **FollowWeight** and **FollowRadius** — control how aggressively **Boids** follow the **Target**.  

---

## **Flocking Parameters Reference**

| **MaxSpeed** | **SeparationWeight** | **AlignmentWeight** | **CohesionWeight** | **Notes** |
|--------------|--------------------|-------------------|------------------|-----------|
| 100          | 3.5                | 1.0               | 0.5              | Default slow speed |
| 150–200      | 4–5                | 1.2–1.5           | 0.7–0.8          | Medium speed |
| 250–400      | 5–6                | 1.5–2.0           | 0.8–1.2          | Fast/chaotic |

> **Tip:** Higher **MaxSpeed** may require increasing weights to keep flocking smooth.  

---


