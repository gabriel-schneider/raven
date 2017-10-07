//
// Created by Gabriel Schneider on 10/7/2017.
//

#ifndef RAVEN_APPLICATIONAWARE_H
#define RAVEN_APPLICATIONAWARE_H


namespace Raven {
    class Application;
    class ApplicationAware {
    protected:
        Application* application;
    public:
        Application *getApplication() const;
        void setApplication(Application *application);

    };
}


#endif //RAVEN_APPLICATIONAWARE_H
