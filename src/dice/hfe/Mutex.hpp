#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif

namespace dice {
    namespace hfe {

        class Mutex {
        public:
            Mutex();
            ~Mutex();

        private:
#ifdef _WIN32
            HANDLE mutex_;
#else
            pthread_mutex_t mutex_;
#endif
        };

        Mutex::Mutex() {
#ifdef _WIN32
            mutex_ = CreateMutex(nullptr, FALSE, nullptr);
#else
            pthread_mutex_init(&mutex_, nullptr);
#endif
        }

        Mutex::~Mutex() {
#ifdef _WIN32
            if (mutex_) {
                CloseHandle(mutex_);
            }
#else
            pthread_mutex_destroy(&mutex_);
#endif
        }

    }
}
