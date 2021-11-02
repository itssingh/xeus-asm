#include "xasm/xasm_interpreter.hpp"

<<<<<<< Updated upstream
std::string asm ::output = "";
=======
<<<<<<< HEAD
namespace xasm {
>>>>>>> Stashed changes

namespace xasm {

<<<<<<< Updated upstream
=======
/**
 * @brief executes the code whenever the client is sending an execute request
 * @param execution_counter Typically the cell number
 * @param &code Code to execute
 */
=======
std::string asm ::output = "";

namespace xasm {

>>>>>>> Add source code for Jupyter Kernel
>>>>>>> Stashed changes
nl::json xasm_interpreter::execute_request_impl(int execution_counter,
                                                const std::string &code,
                                                bool silent, bool store_history,
                                                nl::json user_expressions,
                                                bool allow_stdin) {
<<<<<<< Updated upstream
    // write your logic here
=======
<<<<<<< HEAD
  auto ok = []() {
    nl::json result;
    result["status"] = "ok";
    return result;
  };

  auto create_object =
      [&]() {
        code_runner = new Interpreter();
        code_runner->set_address("0000");
      };
  auto delete_object =
      [&]() {
        delete code_runner;
        code_runner = nullptr;
      };

  // check code_runner object if not exist then create one
  // set address
  // code == HLT ,  destroy code_runner, else continue, return register to
  // publish, store it in memory, update PC and execute the code
  //
  std::vector<std::string>
      traceback;
  auto handle_exception = [&](std::string what) {
    nl::json result;
    result["status"] = "error";
    result["ename"] = "Error";
    result["evalue"] = what;
    traceback.push_back(what);
    publish_execution_error(result["ename"], result["evalue"], traceback);
    traceback.clear();
    return result;
  };

  nl::json pub_data;
  if(!code_runner){
    create_object();
  }
  try {
    if (code_runner->execute(code)) {
      pub_data["text/plain"] = code_runner->getRegister().toString();
      publish_execution_result(execution_counter, std::move(pub_data),
                               nl::json::object());
      if(code=="HLT"){
        delete_object();
      }
      return ok();
    } else {
      throw(code_runner->get_error());
    }
  } catch (const std::exception &err) {
    delete_object();
    return handle_exception(err.what());
  }
  return ok();
=======
    // write your logic here
>>>>>>> Add source code for Jupyter Kernel
>>>>>>> Stashed changes
}

nl::json xasm_interpreter::complete_request_impl(const std::string &code,
                                                 int cursor_pos) {
  nl::json result;
  result["status"] = "ok";
  return result;
}

<<<<<<< Updated upstream
// 
=======
<<<<<<< HEAD
=======
// 
>>>>>>> Add source code for Jupyter Kernel
>>>>>>> Stashed changes
nl::json xasm_interpreter::inspect_request_impl(const std::string &code,
                                                int cursor_pos,
                                                int detail_level) {
  nl::json result;
  result["status"] = "ok";
  return result;
}

<<<<<<< Updated upstream
//syntax check
=======
<<<<<<< HEAD
// syntax check
=======
//syntax check
>>>>>>> Add source code for Jupyter Kernel
>>>>>>> Stashed changes
nl::json xasm_interpreter::is_complete_request_impl(const std::string &code) {
  nl::json result;
  result["status"] = "complete";
  return result;
<<<<<<< Updated upstream
} 

void xasm_interpreter::configure_impl() {}
=======
<<<<<<< HEAD
}
=======
} 

void xasm_interpreter::configure_impl() {}
>>>>>>> Add source code for Jupyter Kernel
>>>>>>> Stashed changes

nl::json xasm_interpreter::kernel_info_request_impl() {
  nl::json info;
  info["implementation"] = "xasm";
  info["implementation_version"] = "0.1.0";
<<<<<<< Updated upstream
  std::string banner = R"V0G0N(                                                             
=======
<<<<<<< HEAD
  std::string banner = R"V0G0N(

=======
  std::string banner = R"V0G0N(                                                             
>>>>>>> Add source code for Jupyter Kernel
>>>>>>> Stashed changes
      xeus-asm: a Jupyter Kernel for asm Language
      xASM Version: 0.1.0")V0G0N";
  info["banner"] = banner;
  info["language_info"]["name"] = "asm";
<<<<<<< Updated upstream
  info["langauge_info"]["codemirror_mode"] = "vb";
  info["language_info"]["version"] = "0.1.0";
  info["language_info"]["mimetype"] = "text/x-vb";
  info["language_info"]["file_extension"] = ".bas";
=======
<<<<<<< HEAD
  info["langauge_info"]["codemirror_mode"] = "c";
  info["language_info"]["version"] = "0.1.0";
  info["language_info"]["mimetype"] = "text/x-asm";
  info["language_info"]["file_extension"] = ".asm";
=======
  info["langauge_info"]["codemirror_mode"] = "vb";
  info["language_info"]["version"] = "0.1.0";
  info["language_info"]["mimetype"] = "text/x-vb";
  info["language_info"]["file_extension"] = ".bas";
>>>>>>> Add source code for Jupyter Kernel
>>>>>>> Stashed changes
  return info;
}

void xasm_interpreter::shutdown_request_impl() {}
} // namespace xasm
