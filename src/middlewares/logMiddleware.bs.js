// Generated by BUCKLESCRIPT VERSION 2.2.3, PLEASE EDIT WITH CARE
'use strict';


function logMiddleware(reducer) {
  console.log("LOG", reducer[1], reducer[0]);
  return reducer;
}

exports.logMiddleware = logMiddleware;
/* No side effect */