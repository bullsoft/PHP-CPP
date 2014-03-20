/**
 *  Implementation of the exception that was originally thrown by PHP
 *  code or the zend engine, and that could or could not be picked
 *  up by C++ code
 *
 *  @author Emiel Bruijntjes <emiel.bruijntjes@copernica.com>
 *  @copyright 2013 Copernica BV
 */
#include "includes.h"
#include <php.h>
#include "zend_exceptions.h"

void cpp_throw_exception_hook(struct _zval_struct *exception)
{
  throw Php::OrigException(exception);
}

/**
 *  Set up namespace
 */
namespace Php {

/**
 *  Destructor
 */
OrigException::~OrigException() noexcept
{
    // skip if the exception was restored
    if (_restored) return;
    // clean up the exception, because it was handled in C++ code
    zend_clear_exception();
}
                                         

/**
<<<<<<< HEAD
 *  Restore the exception
 *  @internal
 */
void OrigException::restore()
{
    std::cout << "restore the exception" << std::endl;
    
    // restore the exception
    zend_exception_restore();
    
    // mark exception as restored
    _restored = true;
}

void OrigException::hook()
{
  zend_throw_exception_hook = cpp_throw_exception_hook;
}
                                            
                                            
/**
=======
>>>>>>> 6d42a8f99cbe98201a0d52ab276f6929b66cfe4f
 *  End of namespace
 */
}

