#pragma once

#include <depthai/pipeline/Node.hpp>

// shared
#include <depthai-shared/generated/XLinkOutProperties.hpp>
#include <depthai-shared/generated/Generators.hpp>

namespace dai
{
    namespace node
    {
        class XLinkOut : public Node {
            dai::gen::XLinkOutProperties properties;
        
            std::string getName(){
                return "XLinkOut";
            }

        
            std::vector<Input> getInputs(){
                return {in};
            }
            
            std::vector<Output> getOutputs(){
                return {};
            }

            nlohmann::json getProperties(){
                nlohmann::json j;
                nlohmann::to_json(j, properties);
                return j;
            }

            std::shared_ptr<Node> clone(){
                return std::make_shared<XLinkOut>(*this);
            }
        
        public:
            XLinkOut(const std::shared_ptr<PipelineImpl>& par) : Node(par) {}

            Input in{*this, "in", Input::Type::SReceiver, {{DatatypeEnum::RawBuffer, true}} };

            void setStreamName(std::string name){
                properties.streamName = name;
            }

            void setFpsLimit(double fps){
                properties.maxFpsLimit = fps;
            }

        };

    } // namespace node
} // namespace dai
