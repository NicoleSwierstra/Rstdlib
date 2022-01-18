//Easing functions for animations & whatnot

namespace rstdpp {
    //linear interpolation
    <template <typename T>>
    inline T lerp(T a, T b, double t){
        return a + t * (b - a);
    }

    //scales the values entered to [0, 1]
    <template <typename T>>
    inline T scale01(T value, T min, T max){
        return (value - min) / (max - min);
    }

    //scales the values entered to [-1, 1]
    <template <typename T>>
    inline T scalen11(T value, T min, T max){
        return scale01(value, min + ((max - min) * 0.5), max);
    }

    //full remap between ab0 and ab1
    <template <typename T>>
    inline T remapValues(T value, T a0, T b0, T a1, T b1){
        return lerp(a1, b1, (double)scale01(value, a0, b0));
    }

    /* Normalized functions */

    // misc

    <template <typename T>>
    inline T PingPong(T value) {
        return fabs(1 - fabs(1 - T % 2));
    }

    // smooth starts

    <template <typename T>>
    inline T SmoothStart2(T value) {
        return value * value;
    }

    <template <typename T>>
        inline T SmoothStart3(T value) {
        return value * value * value;
    }

    <template <typename T>>
        inline T SmoothStart4(T value) {
        return value * value * value * value;
    }

    // smooth stops

    <template <typename T>>
    inline T SmoothStop2(T value) {
        return 1 - SmoothStart2(1 - value);
    }

    <template <typename T>>
    inline T SmoothStop3(T value) {
        return 1 - SmoothStart3(1 - value);
    }

    <template <typename T>>
    inline T SmoothStop4(T value) {
        return 1 - SmoothStart4(1 - value);
    }

    // smooth steps (why is it called smooth step it makes me think the line looks like a wavy stair or something)

    <template <typename T>>
    inline T SmoothStep2(T value) {
        return lerp(SmoothStart2(T), SmoothStop2(T), (double)T);
    }

    <template <typename T>>
    inline T SmoothStep3(T value) {
        return lerp(SmoothStart3(T), SmoothStop3(T), (double)T);
    }

    <template <typename T>>
    inline T SmoothStep4(T value) {
        return lerp(SmoothStart4(T), SmoothStop4(T), (double)T);
    }

    // sharp curves

    <template <typename T>>
    inline T SmoothStep2(T value) {
        return SmoothStart2(PingPong(value * 2));
    }

    <template <typename T>>
    inline T SmoothStep3(T value) {
        return SmoothStart3(PingPong(value * 2));
    }

    <template <typename T>>
    inline T SmoothStep4(T value) {
        return SmoothStart4(PingPong(value * 2));
    }

    // bell curves

    <template <typename T>>
        inline T SmoothStep2(T value) {
        return SmoothStop2(PingPong(value * 2));
    }

    <template <typename T>>
        inline T SmoothStep3(T value) {
        return SmoothStop3(PingPong(value * 2));
    }

    <template <typename T>>
        inline T SmoothStep4(T value) {
        return SmoothStop4(PingPong(value * 2));
    }

    //
}