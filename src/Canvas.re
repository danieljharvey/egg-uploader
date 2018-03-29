/* This is the basic component. */
let component = ReasonReact.statelessComponent("CanvasComponent");

/* Your familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~message="hello", [||]))` */
let make = (~reducerInterface: Types.reducerInterface, _children) => {
  ...component,
  render: self_ =>
    <div>
      <canvas
        onMouseDown=(
          _event =>
            reducerInterface.send(
              Types.MouseDown(
                ReactEventRe.Mouse.clientX(_event),
                ReactEventRe.Mouse.clientY(_event),
              ),
            )
        )
        onMouseMove=(
          _event =>
            reducerInterface.send(
              Types.MouseMove(
                ReactEventRe.Mouse.clientX(_event),
                ReactEventRe.Mouse.clientY(_event),
              ),
            )
        )
        onMouseUp=(
          _event =>
            reducerInterface.send(
              Types.MouseUp(
                ReactEventRe.Mouse.clientX(_event),
                ReactEventRe.Mouse.clientY(_event),
              ),
            )
        )
      />
    </div>,
};