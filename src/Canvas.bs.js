// Generated by BUCKLESCRIPT VERSION 2.2.3, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("Page");

function make(reducerInterface, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", undefined, React.createElement("canvas", {
                      onMouseDown: (function (_event) {
                          return Curry._1(reducerInterface[/* send */1], /* MouseDown */Block.__(0, [
                                        _event.clientX,
                                        _event.clientY
                                      ]));
                        }),
                      onMouseMove: (function (_event) {
                          return Curry._1(reducerInterface[/* send */1], /* MouseMove */Block.__(1, [
                                        _event.clientX,
                                        _event.clientY
                                      ]));
                        }),
                      onMouseUp: (function (_event) {
                          return Curry._1(reducerInterface[/* send */1], /* MouseUp */Block.__(2, [
                                        _event.clientX,
                                        _event.clientY
                                      ]));
                        })
                    }));
    });
  return newrecord;
}

exports.component = component;
exports.make = make;
/* component Not a pure module */