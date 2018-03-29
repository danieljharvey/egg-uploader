/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("ReducerComponent");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (~middlewares: list(Types.middleware), ~initial, _children) => {
  /* spread the other default fields of component here and override a few */
  ...component,
  initialState: () => initial,
  /* State transitions */
  reducer: PipeMiddlewares.doReducer(middlewares),
  render: self => {
    let reducerInterface: Types.reducerInterface = {
      state: self.state,
      send: self.send,
    };
    <Canvas reducerInterface />;
  },
};