#include "Singleton.h"
#include "const.h"

class HttpConnection;

using HttpHandler = std::function<void(std::shared_ptr<HttpConnection>)>;

class LogicSystem : public Singleton<LogicSystem> {
    friend class Singleton<LogicSystem>;

public:
    ~LogicSystem();
    bool HandleGet(std::string, std::shared_ptr<HttpConnection>);
    void RegGet(std::string, HttpHandler handler);

private:
    LogicSystem();
    std::map<std::string, HttpHandler> _post_handler;
    std::map<std::string, HttpHandler> _get_handler;
};
