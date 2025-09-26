#include "EvilCrab.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/physics_body2d.hpp>

using namespace godot;

void EvilCrab::_bind_methods() {
    // Bind speed property
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &EvilCrab::set_speed);
    ClassDB::bind_method(D_METHOD("get_speed"), &EvilCrab::get_speed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

    // Bind stop method so other nodes can call it
    ClassDB::bind_method(D_METHOD("stop_moving"), &EvilCrab::stop_moving);

    // Bind collision handler
    ClassDB::bind_method(D_METHOD("on_body_entered", "body"), &EvilCrab::on_body_entered);

    // Register signal
    ADD_SIGNAL(MethodInfo("crab_touched_player"));
}

EvilCrab::EvilCrab() {
    speed = 100.0f;
    screen_bottom = 700.0f;   // bottom of screen (a little above 720)
    hitbox = nullptr;

    left_limit = 20.0f;       // just inside the left edge
    right_limit = 460.0f;     // just inside the right edge (480 - margin)
    direction = 1;            // start moving right
}

EvilCrab::~EvilCrab() {}

void EvilCrab::_ready() {
    // Assume crab node already has an Area2D + CollisionShape2D as child in editor
    hitbox = get_node<Area2D>("Area2D");
    if (hitbox) {
        hitbox->connect("body_entered", Callable(this, "on_body_entered"));
    }
    else {
        UtilityFunctions::print("EvilCrab: No Area2D child found!");
    }
}

void EvilCrab::_process(double delta) {
    Vector2 pos = get_position();

    // Move crab horizontally
    pos.x += direction * speed * delta;
    pos.y = screen_bottom; // stay locked near bottom
    set_position(pos);

    // Bounce off edges
    if (pos.x <= left_limit) {
        direction = 1; // go right
    }
    else if (pos.x >= right_limit) {
        direction = -1; // go left
    }
}


void EvilCrab::on_body_entered(Node* body) {
    if (body->is_in_group("player")) {  // requires player to be in "player" group
        UtilityFunctions::print("Crab touched player!");
        emit_signal("crab_touched_player");
    }
}

void EvilCrab::stop_moving() {
    speed = 0.0f;
}

void EvilCrab::set_speed(float p_speed) {
    speed = p_speed;
}

float EvilCrab::get_speed() const {
    return speed;
}
