/**
 * @author [Mahmoud Ashraf]
 * @email [M.ashraf.g02@gmail.com]
 * @create date 2022-09-17 18:27:49
 * @modify date 2022-09-17 18:27:49
 * @desc [description]
 */

#ifndef _STATES_H_
#define _STATES_H_

#define STATE_define(_state_fun_)   void ST_##_state_fun_()
#define STATE(_state_fun_)          ST_##_state_fun_

#endif
