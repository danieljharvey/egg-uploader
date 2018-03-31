/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("CanvasReducer");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make =
    (
      ~middlewares:
         list(PipeTypes.middleware(CanvasTypes.action, CanvasTypes.state)),
      ~initial,
      _children,
    ) => {
  /* spread the other default fields of component here and override a few */
  ...component,
  initialState: () => initial,
  /* State transitions */
  reducer: PipeMiddlewares.doReducer(middlewares),
  render: self => {
    let reducerInterface:
      PipeTypes.reducerInterface(CanvasTypes.action, CanvasTypes.state) = {
      state: self.state,
      send: self.send,
    };
    <Canvas reducerInterface />;
  },
};