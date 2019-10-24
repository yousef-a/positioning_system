#pragma once

class HeadingProvider {

    public:
        virtual double getHeading() = 0;
        HeadingProvider();
        ~HeadingProvider();
};